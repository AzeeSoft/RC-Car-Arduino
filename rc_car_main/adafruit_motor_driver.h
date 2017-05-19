#include "MotorDriver.h"

namespace Azeesoft
{
  class Motor : public MotorDriver
  {
    private:
      AF_DCMotor motor;
      int currentSpeed;

    public:
    /*
     * @brief Class constructor
     * @param number The DC Motor Number to control, from 1 to 4
     */
      Motor(int number) : MotorDriver(), motor(number), currentSpeed(0)
      {
        
      }

      void setSpeed(int speed)
      {
        currentSpeed=speed;
        if(speed>0)
        {
          motor.setSpeed(speed);
          motor.run(BACKWARD);
        }
        else
        {
          motor.setSpeed(-speed);
          if(speed<0)
            motor.run(FORWARD);
          else
            motor.run(BRAKE);
        }
      }

      int getSpeed() const
      {
        return currentSpeed;
      }
  };
};
