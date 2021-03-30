#include "mbed.h"
#include <thread>
#include "uLCD_4DGL.h"
using namespace std::chrono;

// Initialize a pins to perform analog and digital output functions
// Adjust analog output pin name to your board spec.
int sample = 476;
int i;
float ADCdata[476];
uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;
AnalogOut  aout(PA_4);
AnalogIn Ain(A0);
DigitalOut dout(LED1);
DigitalIn pin1(D4);
DigitalIn pin2(D5);
DigitalIn pin3(D6);
Thread thread;
Thread thread_1;
void thread_out(){
    while(true)
    {
    for (i = 0; i < sample; i++){
        printf("%f\r\n", ADCdata[i]);
        ThisThread::sleep_for(1ms/sample);
    }
    }
}
void thread_sample()
{
   while (true)
   {
    for (i = 0; i < sample; i++){
        ADCdata[i] = Ain;
        ThisThread::sleep_for(1ms/sample);
    }
   }
}

int mod;
int main(void)
{
    thread.start(thread_sample);
    thread_1.start(thread_out);
   while (true) {
    //uLCD.cls();
   if ((pin1+pin2+pin3)!=0)
        {
            if(pin3==1)
            {
                mod=3;
                uLCD.printf("mod3");
                uLCD.printf("\n");
            }
            else if(pin2==1)
            {
                mod=2;
                uLCD.printf("mod2");
                uLCD.printf("\n");
            }
            else
            {
                mod=1;
            }
        }
    
      // change the voltage on the digital output pin by 0.1 * VCC
      //  and print what the measured voltage should be (assuming VCC = 3.3v)
      for (float i = 0.0; i < 1.0; i += (0.003/mod)) {
            aout = i;
            wait_us(25);
            //ThisThread::sleep_for(5ms);
      }
      for (float i = 1.0; i > 0; i -= (0.007/mod)) {
            aout = i;
            wait_us(25);
            //ThisThread::sleep_for(5ms);
      }
   }
}