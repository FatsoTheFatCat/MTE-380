#include <Servo.h>
Servo esc1;
Servo esc2;
Servo esc3;

const int ESC1_SIGNAL = 22;
const int  ESC2_SIGNAL = 24;
const int  ESC3_SIGNAL = 26;

const int  STOP_VAL = 90;
const int  STOP_VAL_BLACK = 100; // black shaded -> stop value is 100

void setup()
{
  esc1.attach(ESC1_SIGNAL);     // Specify here the pin number on which the signal pin of ESC is connected.
  esc1.write(STOP_VAL_BLACK);   // Initialize to stopped position
  
  esc2.attach(ESC2_SIGNAL);  
  esc2.write(STOP_VAL);
  
  esc3.attach(ESC3_SIGNAL);
  esc3.write(STOP_VAL);
  delay(1000);            // ESC initialization delay.
}

void loop()
{
  esc1.write(90);
  delay(1000);
  esc1.write(STOP_VAL_BLACK);
  delay(2000);
  
  esc2.write(95);
  delay(1000);
  esc2.write(STOP_VAL);
  delay(2000);
  
  esc3.write(95);
  delay(1000);
  esc3.write(STOP_VAL);
  delay(2000);
}
