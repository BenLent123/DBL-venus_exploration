#include <Servo.h>  
const int pingPin = 9;
Servo servoLeft;                             
Servo servoRight;
Servo ultrasound;
int counter = 0;

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
  int scanRes = 0;
  counter++;

 if (counter > 20){
    scanRes = periodicScan();
    delay(1000);
    counter = 0;
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
    delay(150);
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
  //movement
  servoLeft.detach();
  servoRight.detach();
}  

 int periodicScan() {
Serial.print("printing now");
int n;
long USDistance;
stop();
n = 0;
ultrasound.write(n);
delay(300);
USDistance = ping();
if (USDistance > 20 || USDistance == 0){
    return(n);
  }
n = 180;
ultrasound.write(n);
delay(600);
USDistance = ping();
if (USDistance > 20 || USDistance == 0){
    return(n);
   
  }
return(-1);

}
