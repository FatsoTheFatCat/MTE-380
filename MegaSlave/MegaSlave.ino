// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006
 
#include <Servo.h>

byte prevButtonState = 0;
byte nextButtonState = 0;

byte prev = 0;
byte next = 0;


Servo left;
Servo elev;
Servo right;
Servo elev2;

const int ESC1_PIN = 8; // (95/90)
const int ESC2_PIN = 9; //(95/100)
const int ESC3_PIN = 10; // (85/90)
const int ESC4_PIN = 11; // (80/90)

const int START_LEFT = 110;
const int STOP_LEFT = 100;

const int START_RIGHT = 110;
const int STOP_RIGHT = 90;

const int START_ELEV2 = 70;
const int STOP_ELEV2 = 90;

const int START_ELEV = 75;
const int STOP_ELEV = 90;

const int START_VAL = 95;
const int REVERSE_VAL = 80;


///////////////// Motor Movements /////////////////
// Forward Motion Control
void moveForward() {
  left.write(START_LEFT - 10);
  right.write(START_RIGHT - 10);
}
void stopForward() {
  left.write(STOP_LEFT);
  right.write(STOP_RIGHT);
}

// Elevation Motors Control
void moveDown() {
  elev.write(START_ELEV);
  elev2.write(START_ELEV2);
}
void stopDown() {
  elev.write(STOP_ELEV);
  elev2.write(STOP_ELEV2);
}

// Right Motor Control
void turnRight() {
  right.write(START_RIGHT);
}
void stopRight() {
  right.write(STOP_RIGHT);
}

// Left Motor Control
void turnLeft() {
  left.write(START_LEFT);
}
void stopLeft() {
  left.write(STOP_LEFT);
}

// Reverse Motion Control
void reverse() {
  left.write(REVERSE_VAL);
  right.write(REVERSE_VAL);
}
void stopReverse() {
  stopForward();
}


void setup() {
  Serial.begin(9600);
    pinMode(LED_BUILTIN, OUTPUT);
  
  left.attach(ESC2_PIN);     // Specify here the pin number on which the signal pin of ESC is connected.
  left.write(STOP_LEFT);   // Initialize to stopped position
  
  elev.attach(ESC3_PIN);  
  elev.write(STOP_ELEV);
  
  right.attach(ESC1_PIN);
  right.write(STOP_RIGHT);

  elev2.attach(ESC4_PIN);
  elev2.write(STOP_ELEV2);
  
  delay(3000);            // ESC initialization delay.
}

void loop() {
  if (Serial.available()) {
    nextButtonState = Serial.read(); // receive byte

    prev = prevButtonState & 1;
    next = nextButtonState & 1;
    
    if ( prev != next) {
      if (next == 1) {
        moveForward();
      } else {
        stopForward();
      }
    }
    
    prev = (prevButtonState & 2) >> 1;
    next = (nextButtonState & 2) >> 1;
    
    if ( prev != next) {
      if (next == 1) {
        moveDown();
      } else {
        stopDown();
      }
    }
      
    prev = (prevButtonState & 4) >> 2;
    next = (nextButtonState & 4) >> 2;
    
    if ( prev != next) {
      if (next == 1) {
        turnRight();
      } else {
        stopRight();
      }
    }
      
    prev = (prevButtonState & 8) >> 3;
    next = (nextButtonState & 8) >> 3;
    
    if ( prev != next) {
      if (next == 1) {
        turnLeft();
      } else {
        stopLeft();
      }
    }
      
    prev = (prevButtonState & 16) >> 4;
    next = (nextButtonState & 16) >> 4;
    
    if ( prev != next) {
      if (next == 1) {
        reverse();
      } else {
        stopReverse();
      }
    }

    prevButtonState = nextButtonState;
  }
}

