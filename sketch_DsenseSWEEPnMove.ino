#include <Servo.h>  
const int pingPin = 9;
Servo servoLeft;                             
Servo servoRight;
Servo ultrasound;
int counter = 0;
int scanRes = 0;

void setup() {

Serial.begin(9600);
servoLeft.attach(13);                   
servoRight.attach(12);
ultrasound.attach(11); 
sensorsetup();

}


void sensorsetup(){
  ultrasound.write(90);
  delay(100);
  return(1);
}


void loop() {
  long USDistance;
  counter++;

 if (counter > 10){
    scanRes = periodicScan();
    counter = 0;
    ultrasound.write(90);
    if (scanRes = 0) {
      backward();
      delay(200);
      spinL();
      delay(300);
    }
    if (scanRes = 180){
      backward();
      delay(200);
      spinR();
      delay(300);
    }
    

    // move according to res of scan res
  }
  
  ultrasound.write(50); 
  for(int i = 50;i<130;i++){
    ultrasound.write(i);
    USDistance = ping();
    if (USDistance > 20 || USDistance == 0){
    forward();
   
  }
  else {
    backward();
    delay(200);
    spinR();
    delay(250);
    ultrasound.write(90);
  }

    
  } 

}



long ping(){
  long duration, USDistance;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  USDistance = duration / 29 / 2;
  printDistance(USDistance);
  return(USDistance);
}

void printDistance(long USDistance){
  Serial.print(USDistance);
  Serial.print("cm");
  Serial.println();
}

void forward() {
  servoLeft.attach(13);                   
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1300);         
  servoRight.writeMicroseconds(1700);
}    

void backward() {
  servoLeft.attach(13);                   
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1700);         
  servoRight.writeMicroseconds(1300);
}   

void spinR() {
  servoLeft.attach(13);                   
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1700);         
  servoRight.writeMicroseconds(1700);
} 

void spinL() {
  servoLeft.attach(13);                   
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1300);         
  servoRight.writeMicroseconds(1300);
}  

void stop() {
  servoLeft.detach();
  servoRight.detach();
}  


int periodicScan() {
long USDistance;
int n = -1;
stop();
for (int i = 0; i<200; i = i + 180){
ultrasound.write(i);
delay(1000);
USDistance = ping();

if (USDistance < 20 && USDistance != 0){
    n = i;
    return(n);
  }

}



return(n);

}