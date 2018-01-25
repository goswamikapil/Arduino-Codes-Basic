/*
this programe will control the brightness of LED with IR remote

*/

#include<IRremote.h>

int rp = 7;// IR recieve pin
int lp = 10; // led pin

IRrecv irrecv(7);

decode_results results;
boolean val1 = LOW;
    int val2;


void setup() {
     Serial.begin(9600);
     irrecv.enableIRIn();
     pinMode(lp, OUTPUT);
}

void loop(){
     int t;
     if (irrecv.decode(&results)){
         Serial.println(results.value, DEC);
         t = results.value;
         switch (t){
           
                case 16740495:
                     val1 = !val1;
                     digitalWrite(13, val1);
                     break;
                
               case 16713975:
                    val2 = val2 + 51;
                    analogWrite(13, val2);
                    break;
      
               case 16746615:
                    val2 = val2-51;
                    analogWrite(13, val2);
                    break;
                    
               default:
                       ;
              }
              
         irrecv.resume();
        }
        
}
      


