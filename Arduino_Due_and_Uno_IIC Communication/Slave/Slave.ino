// slave code

/*
 arduino Due - arduino Uno
    sda      -  sda
    scl      -  scl
 */

#include<Wire.h>


void setup() {
     Serial.begin(9600);
     Wire.begin(5);
     Wire.onReceive(receiveEvent);
     pinMode(13, OUTPUT); // LED output
     digitalWrite(13, LOW);
    }

void loop() {

}

void receiveEvent(int howMany)
{
  while(Wire.available())
  {
    char c = Wire.read();
    Serial.println(c);
    if (c == 'H')
    digitalWrite(13,HIGH);
    if (c == 'L')
    digitalWrite(13,LOW);
  }
}
    
