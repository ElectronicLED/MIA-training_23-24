/*
 * File: slave.ino
 * Author: Nour ElDeen Shalaby
 * Description: 
 * Date: 21/8/2023
 */

#include <Wire.h>


int LED = 11;
//variable to store received command
int x = 0;

void setup() {
  
  Serial.begin(9600);
  
  
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 69
  Wire.begin(69); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}


void receiveEvent(int bytes) {
  x = Wire.read();   
 // Serial.println(x);
}


void loop() {

  if (x == 2) {

    analogWrite(LED, 127);
    Serial.println("Vector focused");
  }
  
  if (x == 3) {
    
    analogWrite(LED, 191);
    Serial.println("Vector distracted");
  }

  if (x == 4) {
    
    analogWrite(LED, 255);
    Serial.println("Glitch");
  }
  

}