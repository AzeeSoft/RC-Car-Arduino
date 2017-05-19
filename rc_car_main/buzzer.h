#include <pitches.h>

namespace Azeesoft
{
  class Buzzer
  {
      private:
        int melody[8] = {NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_A5, NOTE_B5, NOTE_C6};
        int pin;
        
      public:
        Buzzer(int p): pin(p)
        {
          
        }

        void playSuccessfulConnectionSound()
        {
          int note_duration=500;
          for (int thisNote = 0; thisNote < 8; thisNote++) {
            // pin8 output the voice, every scale is 0.5 sencond
            tone(pin, melody[thisNote], note_duration);
             
            // Output the voice after several minutes
            delay(100);
          }
        }

        void playInitializationSound()
        {
          tone(pin, 116.54, 1000/8);
          delay(1000/8);
          tone(pin, 155.56, 1000/8);
          delay(1000/8);
          tone(pin, 233.08, 1000/8);
          delay(1000/8 + 1);
          
          tone(pin, 311.13, 1000/4);
          delay(1000/4);
          tone(pin, 290.13, 1000/4);
          delay(1000/4);
          tone(pin, 449.23, 1000/4);
          delay(1000/4);
          tone(pin, 469.23, 1000/3);
          delay(1000/3);
         
        }

        void playMISong()
        {
          tone(pin,146.83,400);//D
            delay(400);
          
          tone(pin,146.83,400);//D
             delay(400);
          
          tone(pin,146.83,250);//D
             delay(250);
          
          tone(pin,174.61,250);//F
             delay(250);
          
          tone(pin,196.00,350);//G
             delay(400);
          
          tone(pin,146.83,350);//D
            delay(400);
          
          tone(pin,146.83,200);//D
             delay(250);
          
          tone(pin,146.83,200);//D
             delay(250);
          
           tone(pin,130.81,400);//C
             delay(450);
          
           tone(pin,130.81,400);//C
             delay(450);
          
          tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,146.83,400);//D
             delay(450);
          
           tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,174.61,400);//F
             delay(300);
          
          tone(pin,196.00,400);//G
             delay(450);
          
           tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,146.83,400);//D
             delay(450);
          
           tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,130.81,400);//C
             delay(300);
          
           tone(pin,130.81,400);//C
             delay(300);
          
          tone(pin,130.81,400);//C
             delay(450);
          
          tone(pin,174.61,400);//F
             delay(450);
          
          tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,220.00,400);//A
             delay(450);
          
           tone(pin,174.61,400);//D
             delay(450);
          
          tone(pin,146.83,400);//D
             delay(450);
          
          tone(pin,207.65,400);//GSHARP
             delay(450);
        }

        void playHPSong()
        {
          tone(pin, 493.88, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 1500/3);
          delay(1500/3);
          tone(pin, 783.99, 500/3);
          delay(500/3);
          tone(pin, 739.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 2000/3);
          delay(2000/3);
          tone(pin, 987.77, 1000/3);
          delay(1000/3);
          
          tone(pin, 880.00, 3000/3);
          delay(3000/3);
          
          tone(pin, 739.99, 3000/3);
          delay(3000/3);
          
          tone(pin, 659.25, 1500/3);
          delay(1500/3);
          tone(pin, 783.99, 500/3);
          delay(500/3);
          tone(pin, 739.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 622.25, 2000/3);
          delay(2000/3);
          tone(pin, 698.46, 1000/3);
          delay(1000/3);
          
          tone(pin, 493.88, 5000/3);
          delay(5000/3);
          tone(pin, 493.88, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 1500/3);
          delay(1500/3);
          tone(pin, 783.99, 500/3);
          delay(500/3);
          tone(pin, 739.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 2000/3);
          delay(2000/3);
          tone(pin, 987.77, 1000/3);
          delay(1000/3);
          
          tone(pin, 1174.66, 2000/3);
          delay(2000/3);
          tone(pin, 1108.73, 1000/3);
          delay(1000/3);
          
          tone(pin, 1046.50, 2000/3);
          delay(2000/3);
          tone(pin, 830.61, 1000/3);
          delay(1000/3);
          
          tone(pin, 1046.50, 1500/3);
          delay(1500/3);
          tone(pin, 987.77, 500/3);
          delay(500/3);
          tone(pin, 932.33, 1000/3);
          delay(1000/3);
          
          tone(pin, 466.16, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 5000/3);
          delay(5000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 987.77, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 987.77, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 1046.50, 2000/3);
          delay(2000/3);
          tone(pin, 987.77, 1000/3);
          delay(1000/3);
          
          tone(pin, 932.33, 2000/3);
          delay(2000/3);
          tone(pin, 739.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 783.99, 1500/3);
          delay(1500/3);
          tone(pin, 987.77, 500/3);
          delay(500/3);
          tone(pin, 932.33, 1000/3);
          delay(1000/3);
          
          tone(pin, 466.16, 2000/3);
          delay(2000/3);
          tone(pin, 493.88, 1000/3);
          delay(1000/3);
          
          tone(pin, 987.77, 5000/3);
          delay(5000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 987.77, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 987.77, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 1174.66, 2000/3);
          delay(2000/3);
          tone(pin, 1108.73, 1000/3);
          delay(1000/3);
          
          tone(pin, 1046.50, 2000/3);
          delay(2000/3);
          tone(pin, 830.61, 1000/3);
          delay(1000/3);
          
          tone(pin, 1046.50, 1500/3);
          delay(1500/3);
          tone(pin, 987.77, 500/3);
          delay(500/3);
          tone(pin, 932.33, 1000/3);
          delay(1000/3);
          
          tone(pin, 466.16, 2000/3);
          delay(2000/3);
          tone(pin, 783.99, 1000/3);
          delay(1000/3);
          
          tone(pin, 659.25, 5000/3);
          delay(5000/3);
        }
  };  
};

