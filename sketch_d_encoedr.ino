#include <Servo.h> 
#define REC 8
#define LEC 7
Servo servoLeft;                             
Servo servoRight;

int counter = 0;
int currstateLEC;
int laststateLEC;
int currstateREC;
int laststateREC;


void setup() {
  Serial.begin (9600);
pinMode(REC,INPUT);
pinMode(LEC,INPUT);
laststateLEC = digitalRead(LEC);
laststateREC = digitalRead(REC);
}

void loop() {
encode();
forward();

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

void stop() {
  servoLeft.detach();
  servoRight.detach();
}  

void encode(){
  // Read the current state of CLK
	currstateLEC = digitalRead(LEC);
  	currstateREC = digitalRead(REC);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (currstateLEC != laststateLEC  && currstateREC != laststateREC && currstateLEC == 1 && currstateREC == 1){
			counter ++;
			
		}

		
		Serial.print("Counter: ");
		Serial.println(counter);
	}

