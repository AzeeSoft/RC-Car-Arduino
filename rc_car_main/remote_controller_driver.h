namespace Azeesoft
{  
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

