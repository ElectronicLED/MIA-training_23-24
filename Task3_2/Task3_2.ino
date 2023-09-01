/*
 * Task3_2.ino
 * Author: Nour ElDeen Shalaby
 * Description: Localizing the cookie in the shrink ray chamBer with a "B" not a "P"
 * Date: 21/8/2023
 */


/////////////define the pins///////////
//left ultrasonic
#define leftTrig 13
#define leftEcho 12

//right ultrasonic
#define rightTrig 11
#define rightEcho 10

//front ultrasonic
#define frontTrig 9
#define frontEcho 8

//back ultrasonic
#define backTrig 7
#define backEcho 6


////////position variabels////////
float x_pos = 0.0;
float y_pos = 0.0;

////////distance variables///////
float dist_Left = 0.0;
float dist_Right = 0.0;
float dist_Front = 0.0;
float dist_Back = 0.0;


//getting the distance
float getDistance(int trig,int echo){
    pinMode(trig,OUTPUT);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    pinMode(echo, INPUT);
    return pulseIn(echo,HIGH,30000)/58.0;
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  //reading distances in cm
  dist_Left = getDistance(leftTrig, leftEcho);
  dist_Back = getDistance(backTrig, backEcho);
  dist_Front = getDistance(frontTrig, frontEcho);
  dist_Right = getDistance(rightTrig, rightEcho);


  //since the ultrasonic have a minimum range of 20cm 
  if(dist_Right > dist_Left){
    x_pos = 5 - dist_Right;
  }else{
    x_pos = dist_Left;
  }

  if(dist_Front > dist_Back){
    y_pos = 6 - dist_Front;
  }else{
    y_pos = dist_Back;
  }



}
