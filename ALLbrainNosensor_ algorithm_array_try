#include <Servo.h>
#include <stdio.h>
#include <stdlib.h>
//////////////////////////////////
Servo servoLeft;
Servo servoRight;
Servo servoUltrasound;
Servo gripper;
//////////////////////////////////
#define RXbee 0
#define TX 1
#define ultrasoundPin 9
#define grabberServoPin 10
#define ultrasoundServo 11
#define leftServo 12
#define rightServo 13
#define leftSensor 3   // TO BE CHANGED IR SENSOR
#define rightSensor 3 
#define LENCODER 8
#define RENCODER 7
int nholesR =0;
int nholesL = 0;
bool prevreadL;
bool prevreadR; // TO BE CHANGED IR SENSOR
int counterLoop = 0;
int scanRes = 0;
bool switchTurnDirection = false;
//////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode(LENCODER, INPUT);                   
  pinMode(RENCODER, INPUT);
  servoRight.attach(rightServo);
  servoLeft.attach(leftServo);
  servoUltrasound.attach(ultrasoundServo);
}

typedef struct
{
    char *grid;
    int maxX = 6;
    int maxY = 6;
} navigation_t;

typedef struct
{
    int x = 0;
    int y = 0;
} position_t;

void loop(){

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

