#include "stools.h"

#define ENABLE_ADAFRUIT_MOTOR_DRIVER

#ifdef ENABLE_ADAFRUIT_MOTOR_DRIVER
  #include <AFMotor.h>
  #include "adafruit_motor_driver.h"
  #define LEFT_MOTOR_INIT 1
  #define RIGHT_MOTOR_INIT 4
#endif

#include "rc_car.h"
#include "remote_controller.h"

using namespace Azeesoft;

RCCar car;
RemoteController remoteController(&car);

void setup() {
  Serial.begin(9600);
  
  car.initialize();
  remoteController.initialize();
  
//  pinMode(53,OUTPUT);
//  digitalWrite(53,HIGH);
  
//  car.setSpeed(-180,-180);

//  Serial.println("Test Run Started");
}

void loop() {
  remoteController.updateCar();
  car.run();
    testRun();
}

void testRun()
{
  if(Serial.available()>0){
    String ch = Serial.readStringUntil('\n');
	
    if(ch=="forward")
    {
      Serial.println("Moving forward");
      car.setSpeed(255,255);
    }
    else if(ch=="backward")
    {
      Serial.println("Moving backward");
      car.setSpeed(-255,-255);
    }
    else if(ch=="left")
    {
      Serial.println("Moving left");
      car.setSpeed(0,255);
    }
    else if(ch=="right")
    {
      Serial.println("Moving right");
      car.setSpeed(255, 0);
    }
    else
    {
      Serial.println("Stopping");
      car.setSpeed(0,0);
    }

    car.run();
  }
}
