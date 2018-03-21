// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.




void setup() {
  // initialize the pushbutton pins as inputs:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

byte buttonState = 0;         // variable for reading the pushbutton status

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(2) | digitalRead(3) << 1 | digitalRead(4) << 2 | digitalRead(5) << 3 | digitalRead(6) << 4;

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
//  Serial.print(buttonState & 1);
//  Serial.print((buttonState & 2) >> 1);
//  Serial.print((buttonState & 4) >> 2);
//  Serial.print((buttonState & 8) >> 3);
//  Serial.println((buttonState & 16) >> 4);
  Serial.write(buttonState);   // sends one byte
}
