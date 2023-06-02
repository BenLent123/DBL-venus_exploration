#include <Servo.h>
#define LENCODER 8
#define RENCODER 7
int angles=0;
int numberOfHoles = 0;
bool prevreader;
bool prevdreader;
int disr=(((numberOfHoles)*3.14*6.5)/24);
int disl=(((angles)*3.14*6.5)/24);

void setup() {
  pinMode(LENCODER, INPUT);                        //encoder left
  pinMode(RENCODER, INPUT); 
      
}

void loop(){
  
}

void readEncoders() {
  boolean readwheel = digitalRead(LENCODER);                  //read encoders
  if (readwheel == 1 && readwheel != prevreader) {                  //make sure that it is not the same hole being read
    numberOfHoles += 1;
    prevreader = 1;
  } else if (readwheel == 0) {
    prevreader = 0;
  }
}

void readangles() {
  boolean readwheel = digitalRead(RENCODER);                  //read encoders
  if (readwheel == 1 && readwheel != prevdreader) {                  //make sure that it is not the same hole being read
    angles += 1;
    prevdreader = 1;
  } else if (readwheel == 0) {
    prevdreader = 0;
  }
}
