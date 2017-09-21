#include "asgn2.h"

void setup() {
  pinMode(10, "OUTPUT");
  Serial.begin(9600);
}

void loop() {
  Serial.println(5.0*analogRead(0)/1023);//this reads the output from a potentiometer
  analogWrite(10, analogRead(0)/4);//Sending the read voltage out as a new PWM
  Serial.println(5.0*analogRead(1)/1023);//Outputs the new voltage it is reading after beeing filtered 
}