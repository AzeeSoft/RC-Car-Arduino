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
  car.initialize();
  Serial.begin(9600);
  pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);
  
//  car.setSpeed(-180,-180);
}

void loop() {
  remoteController.updateCar();
  car.run();
}

void testRun()
{
  if(Serial.available()>0){
    String ch = Serial.readStringUntil('\n');
	
    if(ch=="forward")
    {
      car.setSpeed(255,255);
    }
    else if(ch=="backward")
    {
      car.setSpeed(-255,-255);
    }
    else if(ch=="left")
    {
      car.setSpeed(255,0);
    }
    else if(ch=="right")
    {
      car.setSpeed(0,255);
    }
    else
    {
      car.setSpeed(0,0);
    }
  }
}


