#include "remote_controller_driver.h"
      
#define USING_SERIAL Serial1
#define DATA_SPLITTER_COUNT 2

namespace Azeesoft
{
  class Analog: public AnalogDriver
  {
    private:
      int angle=0;
      int strength=0;
      
    public:
      const int MIN_ANGLE=0;
      const int MAX_ANGLE=360;
      const int MIN_STRENGTH=0;
      const int MAX_STRENGTH=100;
      
      Analog(): AnalogDriver()
      {
        
      }

      void setAngle(int a)
      {
        if(a<MIN_ANGLE)
          a=MIN_ANGLE;
        else if(a>MAX_ANGLE)
          a=MAX_ANGLE;

        angle=a;
      }

      void setStrength(int s)
      {
        if(s<MIN_STRENGTH)
          s=MIN_STRENGTH;
        else if(s>MAX_STRENGTH)
          s=MAX_STRENGTH;

        strength=s;
      }

      int getAngle() const
      {
        return angle;
      }

      int getStrength() const
      {
        return strength;
      }
  };

  class RemoteController: public RemoteControllerDriver
  {
    private:
      Analog leftAnalog;
      Analog rightAnalog;
    
      String readIncomingData()
      {
        if(USING_SERIAL.available()>0)
        {
          return USING_SERIAL.readStringUntil('\n');
        }

        return "";
      }

      void updateAnalogs(String data)
      {
         String vals[DATA_SPLITTER_COUNT+1];
         int i=0;
         int pos=data.indexOf(':');
         int lastPos=-1;
         while(pos!=-1){
          if(i>DATA_SPLITTER_COUNT)
            break;
            
            vals[i]=data.substring(lastPos+1,pos);
            i++;
            lastPos=pos;
            pos=data.indexOf(':',pos+1);
         }

         if(vals[0]=="AnalogH")
         {
//            Serial.println("Starts with AnalogH");
//            Serial.println(vals[1].toInt());
            leftAnalog.setAngle(vals[1].toInt());
            leftAnalog.setStrength(vals[2].toInt());
            
//            Serial.println(leftAnalog.getAngle());
         }
         else if(vals[0]=="AnalogV")
         {
//            Serial.println("Starts with AnalogV");
            rightAnalog.setAngle(vals[1].toInt());
            rightAnalog.setStrength(vals[2].toInt());
         }

          String s="Left Analog: "+leftAnalog.getAngle();
          s+=" ; "+leftAnalog.getStrength();
//          Serial.println(leftAnalog.getStrength());
          s="Right Analog: "+rightAnalog.getAngle();
          s+=" ; "+rightAnalog.getStrength();
//          Serial.println(rightAnalog.getStrength());
      }
      
    public:
      RemoteController(RCCar* rcp): RemoteControllerDriver(rcp)
      {
        USING_SERIAL.begin(9600);
      }

      void updateCar()
      {
        String data=readIncomingData();
//        if(data!="")Serial.println("Incoming Data: "+data);
//        String data="ABC";

        if(data.startsWith("AZEE_HANDSHAKE"))
        {
          rc_car_ptr->onRemoteConnectionEstablished();
        }
        else if(data.startsWith("Analog"))
        {
          updateAnalogs(data);
          double h=cos((PI*leftAnalog.getAngle())/180.0) * leftAnalog.getStrength();
          double v=sin((PI*rightAnalog.getAngle())/180.0) * rightAnalog.getStrength();
          rc_car_ptr->updateSpeedFromAnalog(h,v);

//          Serial.println(h);
//          Serial.println(v);
        }

        if(data!="")
          Serial.println("");
      }
  };
};

