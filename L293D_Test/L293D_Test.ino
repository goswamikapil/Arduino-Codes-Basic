int MotorPin1 = 8;
int MptorPin2 = 9;

void setup() {
     // setup pins
     pinMode(mp1, OUTPUT);
     pinMode(mp2, OUTPUT);
    }

void loop() {
     // forward
     digitalWrite(mp1, HIGH);
     digitalWrite(mp2, LOW);
     delay(5000);
     
     //backward
     digitalWrite(mp2, HIGH);
     digitalWrite(mp1, LOW);
     dealy(5000);

     //motor off
     digitalWrite(mp1, LOW);
     digitalWrite(mp2, LOW);
     delay(5000);

     // motor break
     digitalWrite(mp1, HIGH);
     digitalWrite(mp2, LOW);
     delay(5000);
}

