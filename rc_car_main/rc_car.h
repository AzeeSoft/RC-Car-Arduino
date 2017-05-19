#include "buzzer.h"

#define MIN_MOTOR_SPEED -255
#define MAX_MOTOR_SPEED 255
#define SPEED_CORRECTION 190
#define MIN_WORKING_SPEED 200

#define LMOTOR_FWD_DEVIANCE 18
#define LMOTOR_BWD_DEVIANCE -10

#define BUZZER_PIN 53

namespace Azeesoft
{
  class RCCar
  {
    private:
      Motor leftMotor;
      Motor rightMotor;
      Buzzer buzzer;

      int leftSpeed=0;
      int rightSpeed=0;

    public:
      /*
       * @brief Class constructor.
       */
      RCCar():leftMotor(LEFT_MOTOR_INIT), rightMotor(RIGHT_MOTOR_INIT), buzzer(BUZZER_PIN)
      {
        
      }

      /*
       * @brief Initialize the robot
       */
      void initialize()
      {
        leftMotor.setSpeed(0);
        rightMotor.setSpeed(0);
        buzzer.playInitializationSound();
        
      }

      void onRemoteConnectionEstablished()
      {
        buzzer.playSuccessfulConnectionSound();
      }

      void setSpeed(int l, int r)
      {
//        l+=SPEED_CORRECTION*(l/fabs(l));
//        r+=SPEED_CORRECTION*(r/fabs(r));
        
        if(l<MIN_MOTOR_SPEED)
          l=MIN_MOTOR_SPEED;
        else if(l>MAX_MOTOR_SPEED)
          l=MAX_MOTOR_SPEED;

        if(fabs(l)<MIN_WORKING_SPEED)
          l=0;

        if(r<MIN_MOTOR_SPEED)
          r=MIN_MOTOR_SPEED;
        else if(r>MAX_MOTOR_SPEED)
          r=MAX_MOTOR_SPEED;

        if(fabs(r)<MIN_WORKING_SPEED)
          r=0;
          
        leftSpeed=l;
        rightSpeed=r;

        if(leftSpeed>LMOTOR_FWD_DEVIANCE)
          leftSpeed-=LMOTOR_FWD_DEVIANCE;
        else if(leftSpeed<LMOTOR_BWD_DEVIANCE)
          leftSpeed-=LMOTOR_BWD_DEVIANCE;
      }

      int getLeftSpeed() const
      {
        return leftSpeed;
      }

      int getRightSpeed() const
      {
        return rightSpeed;
      }

      void updateSpeedFromAnalog(double h, double v)
      {
        h=(h*(MAX_MOTOR_SPEED - SPEED_CORRECTION))/100;
        v=(v*(MAX_MOTOR_SPEED - SPEED_CORRECTION))/100;
        if(v!=0)
         v+=(SPEED_CORRECTION*(getSign(v)));
    
        if(fabs(v)>MIN_WORKING_SPEED)
          v=255*(getSign(v));

        int lSpeed=(int)v;
        int rSpeed=(int)v;


        Serial.println(v);
        if(fabs(v)<=MIN_WORKING_SPEED && h!=0)
        {
          h+=(SPEED_CORRECTION*(getSign(h)));
          Serial.println("Adding Horizontal Speed Correction");
        }

        int turnFactor = (int)(fabs(h)/1);  // /2

        if(v<0)
          turnFactor*=-1;
      
        if(h<0)
        {
          rSpeed+=turnFactor;
          lSpeed-=turnFactor;
        }
        else
        {
          lSpeed+=turnFactor;
          rSpeed-=turnFactor;
        }

//        Serial.println(lSpeed);
//        Serial.println(rSpeed);

        setSpeed(lSpeed, rSpeed);
        if(leftSpeed!=0 || rightSpeed!=0)
        {
          Serial.println(leftSpeed);
          Serial.println(rightSpeed);
        }
      }

      /*
       * @brief Update the state of the robot based on input from sensor and remote control.
       *  Must be called repeatedly while the robot is in operation.
       */
       void run()
       {
        
        leftMotor.setSpeed(leftSpeed);
        rightMotor.setSpeed(rightSpeed);
       }
  };

};
