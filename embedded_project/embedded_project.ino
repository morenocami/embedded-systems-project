#define TRIG1 2
#define echoPin1 3 
#define TRIG2 A3
#define echoPin2 A2

int duration, distance;

void setup() {
  pinMode(TRIG1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(TRIG2, OUTPUT);
  pinMode(echoPin2, INPUT);
  
  digitalWrite(TRIG1,LOW);
  digitalWrite(TRIG2,LOW);
  
  Serial.begin (115200);
}

void loop() {
  //put inside while loop until stop button is pressed
  if(Serial.available()>0){
    byte x = Serial.read();
    
    if(x==1){
      while(x!=0){
        digitalWrite(TRIG1, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG1, HIGH);
        delayMicroseconds(8);
        digitalWrite(TRIG1, LOW);
        duration = pulseIn(echoPin1, HIGH, 5000);
        
        distance = (duration/2) / 10;
        Serial.write(distance); 
        delayMicroseconds(250);
        
        digitalWrite(TRIG2, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG2, HIGH);
        delayMicroseconds(8);
        digitalWrite(TRIG2, LOW);
        duration = pulseIn(echoPin2, HIGH, 5000);
        
        distance = (duration/2) / 10;
        
        Serial.write(distance);
        delayMicroseconds(250);

        for(r=0; r<50; r++){
          digitalWrite(TRIG, LOW);
          delayMicroseconds(2);
          digitalWrite(TRIG, HIGH);
          delayMicroseconds(8);
          digitalWrite(TRIG, LOW);
          duration = pulseIn(echoPin, HIGH, 5000);
          
          distance = (duration/2) / 10;
          Serial.write(distance);
          delayMicroseconds(250);
        }
      }
    }
  }
}


