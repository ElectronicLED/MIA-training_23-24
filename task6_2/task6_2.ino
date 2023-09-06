//540 pulses = 1 rev

#define pi 3.14
#define wheelDiameter 0.4 //in meters

#define outputA 9
#define outputB 8

int pulseCounter = 0;
bool A_state_prev;
bool A_state;

float wheelRev = 0.0;
float dist_travelled = 0.0;// distance travelled in meters

void setup() {
  // put your setup code here, to run once:
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);

  A_state_prev = digitalRead(outputA);

}

void loop() {
  // put your main code here, to run repeatedly:

  A_state = digitalRead(outputA);

  if(A_state != A_state_prev){
    if(digitalRead(outputB) != A_state_prev){
      pulseCounter ++;
    }else{
      pulseCounter --;
    }
  }

  A_state_prev = A_state;


  wheelRev = pulseCounter/540 ;

  dist_travelled = wheelRev * pi * wheelDiameter;


}
