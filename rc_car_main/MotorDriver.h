namespace Azeesoft
{
  class MotorDriver
  {
    virtual void setSpeed(int speed)=0;
    virtual int getSpeed() const=0;
  }
}

