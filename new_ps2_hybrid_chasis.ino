#include<PS2X_lib.h>
PS2X ps2x;
int xcord=0,ycord=0,rxcord=0,rycord=0;
//motor 1
void m1c(int Speed)
     {
      
      digitalWrite(6,0);//motor1
      analogWrite(7,Speed);
      }
void m1a(int Speed)
     {
      
      digitalWrite(6,1);//motor1
      analogWrite(7,Speed);
     }
     //motor 2
void m2c(int Speed)
     {
      digitalWrite(8,0);//motor2
      analogWrite(9,Speed);
     }
void m2a(int Speed)
     {
      digitalWrite(8,1);//motor2
      analogWrite(9,Speed);
     }
void m3c(int Speed)
     {
      digitalWrite(5,0);//motor 3
      analogWrite(4,Speed);
     }
void m3a(int Speed)
     {
      digitalWrite(5,1);//motor 3
      analogWrite(4,Speed);
}
//motor 4
void m4c(int Speed)
     {
      
      digitalWrite(3,0);//motor 4
      analogWrite(2,Speed);
     }
void m4a(int Speed)
     {
      digitalWrite(3,1);//motor 4
      analogWrite(2,Speed);
     } 


//all off    
void alloff()
     { 
      int Dir = 0;
      digitalWrite(6,Dir);//motor1
      analogWrite(7,0);
      digitalWrite(5,Dir);//motor 3
      analogWrite(4,0);
      digitalWrite(3,!Dir);//motor 4
      analogWrite(2,0);
      digitalWrite(8,Dir);//motor 2
      analogWrite(9,0);
     }
void setup() 
{
   ps2x.config_gamepad(13,12,11,10,true,false);              //spi configuration of ps2// (clk,cmd,att,data)
   Serial.begin(9600);

}

void loop() 
{
   ps2x.read_gamepad();
   xcord = ps2x.Analog(PSS_LX);  //xcord = map(xcord,0,255,-255,255);
   ycord = ps2x.Analog(PSS_LY);  //ycord = map(ycord,0,255,255,-255);
   rxcord = ps2x.Analog(PSS_RX); //rxcord = map(rxcord,0,255,-255,255);   
   rycord = ps2x.Analog(PSS_RY); //rycord = map(rycord,0,255,255,-255);
   Serial.print(xcord); Serial.print("  ");
   Serial.print(ycord);Serial.print("  ");
   Serial.print(rxcord);Serial.print("  ");
   Serial.println(rycord);
 // motor 1  
  if (xcord > 0)
     m1c(xcord); 
  if (xcord < 0)
      m1a(-+xcord);
  if (ycord < 0)
      m1a(-ycord);
  if (ycord > 0)
      m1c(ycord);
//motor 2
  if (xcord < 0)
      m2c(-xcord); 
  if (xcord > 0)
      m2a(xcord);
  if (ycord < 0)
      m2a(-ycord);
  if (ycord > 0)
      m2c(ycord);
//motor 3
  if (xcord<0)
      m3c(-xcord); 
  if (xcord > 0)
      m3a(xcord);
  if (ycord > 0)
      m3a(ycord);
  if (ycord < 0)
      m3c(-ycord);
//motor 4
  if (xcord <0)
      m4c(-xcord); 
  if (xcord > 0)
      m4a(xcord);
  if (ycord < 0)
      m4a(-ycord);
  if (ycord > 0)
      m4c(ycord);
      
      if (rxcord > 0)
      {
        m1c(rxcord);
        m2c(rxcord);
        m3c(rxcord);
        m4a(rxcord);
       }
       if (rxcord < 0)
      {
        m1a(-rxcord);
        m2a(-rxcord);
        m3a(-rxcord);
        m4c(-rxcord);
       }
      
      
      
   
  if (xcord == 0 && ycord == 0 && rxcord == 0 && rycord == 0)
    alloff(); 
}
