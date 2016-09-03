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
        //
        //read left ultrasonic sensor
        digitalWrite(TRIG1, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG1, HIGH);
        delayMicroseconds(8);
        digitalWrite(TRIG1, LOW);
        duration = pulseIn(echoPin1, HIGH, 5000);
        
        distance = (duration/2) / 10;
        Serial.write(distance); 
        delayMicroseconds(250);
        
        //
        //read right ultrasonic sensor
        digitalWrite(TRIG2, LOW);
        delayMicroseconds(2);
        digitalWrite(TRIG2, HIGH);
        delayMicroseconds(8);
        digitalWrite(TRIG2, LOW);
        duration = pulseIn(echoPin2, HIGH, 5000);
        
        distance = (duration/2) / 10;
        
        Serial.write(distance);
        delayMicroseconds(250);

        //
        //check if Android app has indicated stop scanning
        //break out of loop if true
        if(Serial.available()>0){
          if(Serial.read()==0){
            delay(10);
            int q =0;
            for(q; q<10; q++){
              Serial.write(-1);
              delay(10);
            }
            break;
          }
        }
      }
    }
  }
}


