#include <Servo.h>  
Servo servoLeft;                             
Servo servoRight;
Servo servoUltrasound;

#define RXbee 0
#define TX 1
//2 through 6 not in use, digital, some pwm
#define leftEncoderPin 7
#define rightEncoderPin 8
#define ultrasoundPin 9
#define grabberServoPin 10
#define ultrasoundServo 11
#define leftServo 12
#define rightServo 13
//0 through 5 not in use, analog

int counterLoop = 0;
int scanRes = 0;
bool switchTurnDirection = false;

void setup() {
  Serial.begin(9600);
  servoRight.attach(rightServo);                   
  servoLeft.attach(leftServo);
  servoUltrasound.attach(ultrasoundServo); 
  sensorsetup();
}

void sensorsetup(){
  servoUltrasound.write(90);
  delay(100);
  return(1);
}

void loop() {
  int USDistance;
  counterLoop++;
// I and how long the loop takes effect the amount
  if (counterLoop > 5){
    scanRes = periodicScan();
    counterLoop = 0;
    servoUltrasound.write(90);
    if (scanRes == 0) {
      // means something detected at 0 (right?)
      backward();
      delay(50);
      spinR();
      delay(200);
    }
    if (scanRes == 180){
      backward();
      delay(50);
      spinL();
      delay(200);
    }
    
    // move according to res of scan res

    // if(switchTurnDirection == false){
    //   switchTurnDirection = true;
    // }else{
    //   switchTurnDirection = false;
    // }
  }
  
  servoUltrasound.write(50); 
  for(int i = 50;i<130;i++){
    servoUltrasound.write(i);
    USDistance = ping();
    if (USDistance > 20 || USDistance == 0){
      forward();
    
    }
    else {
      backward();
      delay(50);

      if(switchTurnDirection==true){
        spinR();
      }else{
        spinL();
      }
      delay(150);
      servoUltrasound.write(90);
    }
  }

}



int ping(){
  int duration, USDistance;
  pinMode(ultrasoundPin, OUTPUT);
  digitalWrite(ultrasoundPin, LOW);
  delayMicroseconds(2);
  digitalWrite(ultrasoundPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ultrasoundPin, LOW);
  pinMode(ultrasoundPin, INPUT);
  duration = pulseIn(ultrasoundPin, HIGH);
  USDistance = duration / 29 / 2;
  printDistance(USDistance);
  return(USDistance);
}

void printDistance(int USDistance){
  Serial.print(USDistance);
  Serial.print("cm");
  Serial.println();
}

void forward() {
  servoLeft.attach(leftServo);                   
  servoRight.attach(rightServo);
  servoRight.writeMicroseconds(1300);         
  servoLeft.writeMicroseconds(1700);
}    

void backward() {
  servoLeft.attach(leftServo);                   
  servoRight.attach(rightServo);
  servoRight.writeMicroseconds(1700);         
  servoLeft.writeMicroseconds(1300);
}   

void spinL() {
  servoLeft.attach(leftServo);                   
  servoRight.attach(rightServo);
  servoLeft.writeMicroseconds(1700);         
  servoRight.writeMicroseconds(1700);
} 

void spinR() {
  servoLeft.attach(leftServo);                   
  servoRight.attach(rightServo);
  servoLeft.writeMicroseconds(1300);         
  servoRight.writeMicroseconds(1300);
}  

void stop() {
  servoLeft.detach();
  servoRight.detach();
}  


int periodicScan() {
  int USDistance;
  bool left = false;
  bool right = false;
  stop();

  servoUltrasound.write(0);
  delay(750);
  USDistance = ping();
  if(USDistance < 20 && USDistance != 0){
    left = true;
  }
  if(USDistance < 40 && USDistance != 0){
      switchTurnDirection = true;
  }

  
  servoUltrasound.write(180);
  delay(1000);
  USDistance = ping();
  if(USDistance < 20 && USDistance != 0){
    right = true;
  }
  if(USDistance < 40 && USDistance != 0){
      switchTurnDirection = false;
  }

  if(right==true && left == true){
    // obstacles on both sides
    return(90);
  }else if(right==true && left == false){
    // obstactle at direction 180 (left?)
    return(180);
  }else if(right==false && left == true){
    // obstacle at direction 0 (right?)
    return(0);
  }
  return(-1);

  // stop();
  // for (int i = 0; i<200; i = i + 180){
  // ultrasound.write(i);
  // delay(1000);
  // USDistance = ping();
  // if (USDistance < 20 && USDistance != 0){
  //     n = i;
  //     return(n);
  //   }
  // }
  // return(n);
}


void open_gripper() {
gripper.write(90);// set the servo position to 90 degrees 
delay(1000);// wait for 1 sec
}

void close_gripper(){
gripper.write(180);
delay(1000);
}



void infra_ping() 
{
  // check the outputs of the pins 
  int infra_ls = digitalRead(leftSensor);
  int infra_rs = digitalRead(rightSensor);

}

/*void infra_action(){
   //00 = both on white -> move forward
  if (infra_ls == 0 && infra_rs == 0)
  {
    forward();
    //GRIPPER KIT?
  }

  else if (infra_ls == 1 && infra_rs == 1)
  {
    backward();
  }
  

  //01 = right sensor on black -> turn left
  else if (infra_ls == 0 && infra_rs == 1)
  {
    backward();
    delay(150);
    spinL();
  }

  //10 = left sensor on black -> turn right
  else if (infra_ls == 1 && infra_rs == 0)
  {
    backward();
    delay(150);
    spinR();
  }
}
*/

