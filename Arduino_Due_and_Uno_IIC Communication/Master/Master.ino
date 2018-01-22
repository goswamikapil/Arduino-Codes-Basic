// master code arduino due
/*
 arduino Due - arduino Uno
    sda      -  sda
    scl      -  scl
 */
#include<Wire.h>


void setup() {
     Wire.begin();
     delay(2000);
    }

void loop() {
     Wire.beginTransmission(5);// open transimission address = 5
     Wire.write('H');// H= high
     Wire.endTransmission();// close transmission
     delay(3000); // wait for 3 seconds

     
     Wire.beginTransmission(5); // again start transmission address = 5
     Wire.write('L'); // L = low
     Wire.endTransmission(); // close transmission
     delay(3000);// wait for 3 seconds

}
