namespace Azeesoft
{
  class AnalogDriver
  {
      public:
        virtual void setAngle(int a) = 0;
        virtual void setStrength(int s) = 0;
        virtual int getAngle() const = 0;
        virtual int getStrength() const = 0;
  };
  
  class RemoteControllerDriver
  {
      protected:
        RCCar* rc_car_ptr;

      private:
        virtual String readIncomingData()=0;
        
      public:
        RemoteControllerDriver(RCCar* rcp)
        {
          rc_car_ptr = rcp;
        }

      virtual void updateCar()=0;
  };
};

