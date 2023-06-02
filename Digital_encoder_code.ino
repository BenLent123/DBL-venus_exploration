#include <Servo.h>
#define LENCODER 8
#define RENCODER 7
int nholesR =0;
int nholesL = 0;
int rotationsR = 0;
int rotationsL = 0;
bool prevreadL;
bool prevreadR;

void setup() {
  pinMode(LENCODER, INPUT);                   
  pinMode(RENCODER, INPUT);
}
void loop(){}

int leftencoder() {
  boolean readwheel = digitalRead(LENCODER);                  //read encoders
  if (readwheel == 1 && readwheel != prevreadL) {             //make sure that it is not the same hole being read
    nholesL += 1;
    prevreadL = 1;
  } else if (readwheel == 0) {
    prevreadL = 0;
  }
  if (nholesL = 8){
   nholesL = 0;
   rotationsL++:
  }
  
  int distance = (((rotationsL)*3.14*6.5)/24);
  return(distance);

}

int rightencoder() {
  boolean readwheel = digitalRead(RENCODER);                  //read encoders
  if (readwheel == 1 && readwheel != prevreadR) {             //make sure that it is not the same hole being read
    nholesR += 1;
    prevreadR = 1;
  } else if (readwheel == 0) {
    prevreadR = 0;
  }
  if (nholesR = 8){
   nholesR = 0;
   rotationsR++:
  }
  
  int distance = (((rotationsR)*3.14*6.5)/24);
  return(distance);
}

// TRYOUT?!?!?!
/*
int angle(){
int angR = rightencoder();
int angL = leftencoder();

if (angR > angL){
return(1);
}else if (angR < angL) {
return(2);
}
return(-1);
}
*/
