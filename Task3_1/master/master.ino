/*
 * File: master.ino
 * Author: Nour ElDeen Shalaby
 * Description: 
 * Date: 21/8/2023
 */

#include <Wire.h>


#define PB1 13
#define PB2 12


void setup()
{
  pinMode(PB1, INPUT);
  pinMode(PB2, INPUT);
  
  Serial.begin(9600);
  Wire.begin();
  

}

void loop()
{
  /*Serial.print("botton 1: ");
  Serial.print(digitalRead(PB1));
   Serial.print("botton 2: ");
  Serial.println(digitalRead(PB2));*/
  
  if( digitalRead(PB1)== 1  &&  digitalRead(PB2) == 0){
    
    Wire.beginTransmission(69);
    Wire.write(2);            
    Wire.endTransmission();
  
  }
  
  else if( digitalRead(PB1)== 0  &&  digitalRead(PB2) == 1){
    
    Wire.beginTransmission(69);
    Wire.write(3);            
    Wire.endTransmission();
  
  }
  
  else if( digitalRead(PB1)== 1  &&  digitalRead(PB2) == 1){
    
    Wire.beginTransmission(69);
    Wire.write(4);            
    Wire.endTransmission();
  
  }else{
    Wire.beginTransmission(69);
    Wire.write(0);            
    Wire.endTransmission();
  }
    
  
  
}