#include "remote_controller_driver.h"
      
//#define USING_SERIAL Serial
#define USING_SERIAL Serial2

namespace Azeesoft
{
  class RemoteController: public RemoteControllerDriver
  {
    private:
      int inputH;
      int inputV;
    
      String readIncomingData()
      {
        if(USING_SERIAL.available()>0)
        {
          return USING_SERIAL.readStringUntil('\n');
        }

        return "";
      }

      int getValueFromAngleAndStrength(float angle, int strength, int axis = 0) 
      {
          int val = (((axis == 0) ? cos(angle) : sin(angle)) * strength * 255) / 100;
          return val;
      }

      void decodeInputs(String data, String vals[3]) {
        int i=0;
        int pos=data.indexOf(':');
        int lastPos=-1;
        while(pos!=-1){
         if(i>3)
           break;
           
           vals[i]=data.substring(lastPos+1,pos);
           Serial.println(vals[i]);
           i++;
           lastPos=pos;
           pos=data.indexOf(':',pos+1);
        }
      }

    public:
      RemoteController(RCCar* rcp): RemoteControllerDriver(rcp)
      {
        
      }

      void initialize() 
      {
        USING_SERIAL.begin(9600);
        Serial.println("Started RC");
      }

      void updateCar()
      {          
        String data=readIncomingData();
        if(data!="")Serial.println("Incoming Data: "+data);
        
        if(data.startsWith("AZEE_HANDSHAKE"))
        {
          rc_car_ptr->onRemoteConnectionEstablished();
        }
        else if(data.startsWith("Drive:"))
        {
          String vals[3];
          decodeInputs(data, vals);
          inputH = vals[1].toInt();
          inputV = vals[2].toInt();
        
          rc_car_ptr->updateSpeed(inputH,inputV);

          Serial.println(inputH);
          Serial.println(inputV);
        }
        else if(data.startsWith("AnalogH:"))
        {
          String vals[3];
          decodeInputs(data, vals);
          float angle = (vals[1].toInt() * 71) / 4068.0;
          inputH = getValueFromAngleAndStrength(angle, vals[2].toInt(), 0);
          
          Serial.println(inputH);
          Serial.println(inputV);
          rc_car_ptr->updateSpeed(inputH,inputV);
        }
        else if(data.startsWith("AnalogV:")) 
        {
          String vals[3];
          decodeInputs(data, vals);
          float angle = (vals[1].toInt() * 71) / 4068.0;
          inputV = getValueFromAngleAndStrength(angle, vals[2].toInt(), 1);
          
          Serial.println(inputH);
          Serial.println(inputV);
          rc_car_ptr->updateSpeed(inputH,inputV);
        }
      }
  };
};
