#include <Servo.h>
#define SERVOS 3

Servo myServos[SERVOS];
int pins[] = {12, 11, 10};
unsigned long MOVING_TIME = 3000; // moving time is 3 seconds
unsigned long animationStartTime;
unsigned long moveStartTime;
int startAngle = 180; 
int stopAngle  = 0; 

void setup() {
  for (int i = 0; i < SERVOS; i++) {
    myServos[i].attach(pins[i]);
  }
  for (int j = 0; j < 180; j++) {
    for (int k = 0; k < SERVOS; k++) {
      int value = myServos[k].read();
      if (value < 180) {
        myServos[k].write(j + 1);
      }
    }
    delay(20);
  }
}

void loop() {
  delay(5000);
  animationStartTime = millis();
  while (millis() - animationStartTime < 10000) {
    for (int m = 0; m < SERVOS; m++) {
      int newAngle = random(150, 180);
      int newDelay = random(500);
      myServos[m].write(newAngle);
      delay(newDelay);
    }
  }
  delay(3000);
  moveStartTime = millis();
  while (myServos[2].read() > 0) {
    unsigned long now = millis() - moveStartTime;
    int zero = myServos[0].read();
    int one = myServos[1].read();
    int two = myServos[2].read();
    if (zero > 0) {
      myServos[0].write(zero - 1);
    }
    if (now > 3000 && one > 0) {
      myServos[1].write(one - 1);
    }
    if (now > 5500 && two > 0) {
      myServos[2].write(two - 1);
    }
    delay(20);
  }
  myServos[0].detach();
  myServos[1].detach();
  myServos[2].detach();
}
