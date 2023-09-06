#include <Wire.h>


float yaw_angle;



void setup() {

  Wire.begin();

  Wire.beginTransmission(0x68);//imu address
  Wire.write(0x6B);            //calling the reset register
  Wire.write(0x00);            //reseting


  Serial.begin(9600); 

  
} 

//*****************************************************************************************//
void loop() {

  Wire.beginTransmission(0x68);//imu address
  Wire.write(0x47); //the begining of Gyro Z data
  Wire.endTransmission();

  Wire.requestFrom(0x68, 2); //request from the gyro address 2 bytes from the start of last register

  // store the 2 bytes in a singel variable
  // shifting the first MSB to the left by 8 and (OR)ing them with the
  int16_t GYRO_ZOUT Wire.read() << 8 | Wire.read();

  Wire.endTransmission();

  //calculate the angel
  yaw_angle = GYRO_ZOUT / 131;
  

  
}
