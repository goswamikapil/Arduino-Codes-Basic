


void setup() {
     // put your setup code here, to run once:
     Serial.begin(9600);
     Serial2.begin(9600);//bluetooth
}


void loop(){
     String trans;
     String rex;

     while(Serial2.available()>0){
           char transchar=Serial2.read(); 
           trans +=transchar;
            delay(5); //Doesn't work without this bitch
     }
    // print if anything recieved
     if (trans!=""){
        Serial2.println(trans);
        Serial.println(trans);
        trans="";
     }
   
}
    
    
    



