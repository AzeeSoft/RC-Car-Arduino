#define ENABLE_ADAFRUIT_MOTOR_DRIVER

#ifdef ENABLE_ADAFRUIT_MOTOR_DRIVER
  #include <AFMotor.h>
#endif


AF_DCMotor motor(1);

void setup() {
  // put your setup code here, to run once:

  motor.setSpeed(255);
  motor.run(BRAKE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
