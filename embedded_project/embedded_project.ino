#include <Servo.h> 

#define TRIG 6
#define echoPin 7

Servo servo;
unsigned int pos = 0,
            r = 0;

long duration, distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(TRIG,LOW);
  
  servo.attach(12);
  servo.write(90);
  delay(1000);
  
  Serial.begin (115200);
}

void loop() {
  //put inside while loop until stop button is pressed
  if(Serial.available()>0){
    byte x = Serial.read();
    
    if(x==1){
      servo.write(0);
      delay(1000);
      //sweep right
      for(pos = 1; pos < 180; pos += 1) {
        servo.write(pos);
        delay(1);

        for(r=0; r<15; r++){
          digitalWrite(TRIG, LOW);
          delayMicroseconds(2);
          digitalWrite(TRIG, HIGH);
          delayMicroseconds(8);
          digitalWrite(TRIG, LOW);
          duration = pulseIn(echoPin, HIGH, 5000);
          
          distance = (duration/2) / 20;
          Serial.write(distance);
          delay(1);
        }
        Serial.write(-1);
        delay(1);
      }
      Serial.write(-2);
      delay(2);
    }
  }
}


