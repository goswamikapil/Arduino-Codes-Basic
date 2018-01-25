/*
this program will convert any IR remote in to cheap wireless Mouse 

*/


#include<IRremote.h>
// IR library can be found on google easily
int rp = 5; // recieve pin
IRrecv irrecv(rp);
decode_results r;


void setup(){ 
     Mouse.begin();
     irrecv.enableIRIn();
}



void loop(){
     int v;
     
     if (irrecv.decode(&r)){ // check for remote signal
         v = r.value; // store signal for data
        
         switch (v){
                case 16713975://up
                Mouse.move(0,-1,0);
                break;
                
                case 16746615:// down
                Mouse.move(0,1,0);
                break;
                
                case 16762935://left
                Mouse.move(1,0,0);
                break;
                
                case 16730295:// right
                Mouse.move(-1,0,0);
                break;
                
                case 16740495://left click
                Mouse.press(MOUSE_LEFT);
                break;
                
                case 16711935:// right clicik
                Mouse.press(MOUSE_RIGHT);
                break;
                
                default:
                ;
                
               }
         // release both the key    
         Mouse.release(MOUSE_LEFT);
         Mouse.release(MOUSE_RIGHT);
         
         irrecv.resume();// resume the process of recieving data form remote
       }
}
    



