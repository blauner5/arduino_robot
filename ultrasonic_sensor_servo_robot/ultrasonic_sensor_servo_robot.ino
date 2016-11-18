#include <NewPing.h> //NewPing_v1.8
#include <Servo.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 400
int leftdist = 0;
int rightdist = 0;
int dist=0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo servo_left;
Servo servo_right;
Servo servo_find;
 
void setup() {
  servo_left.attach(10);
  servo_right.attach(11);
  servo_find.attach(12);
  servo_find.write(90);
  Serial.begin(9600);
  delay(700);
}
 
void loop() {
  
  dist=sonar.ping_cm(); //salvo sulla variabile lettura i CM del sensore ultrasuoni
  
  //Serial.print(lettura); //I write the values on the monitor
  //Serial.println("cm");
  
  if(dist<10){
    findroute();
  }
  else{
    forward();
  }
  delay(100);
}

void alt(){
  servo_left.writeMicroseconds(1500); //stop function servo
  servo_right.writeMicroseconds(1500);
}


void forward(){
  servo_left.writeMicroseconds(2500); //forward first servo
  servo_right.writeMicroseconds(2500);
}

void turnleft () {
  servo_left.writeMicroseconds(2500);    //correct the direction<----------------
  servo_right.writeMicroseconds(2500);   //correct the direction
  delay(1000);
  alt();
  return;
}

void turnright () {
  servo_left.writeMicroseconds(2500);    //correct the direction<----------------
  servo_right.writeMicroseconds(2500);   //correct the direction
  delay(1000);
  alt();
  return;
}

void findroute(){
  alt();
  lookleft();
  lookright();
  if(leftdist < rightdist){
    turnleft();
  }
  else{
    turnright();
  }
}


//functions to find the correct direction
void lookleft() {
  servo_find.write(150);
  delay(700);
  leftdist = sonar.ping_cm();
  servo_find.write(90);
  delay(700);
  return;
}

void lookright () {
  servo_find.write(30);
  delay(700);
  rightdist = sonar.ping_cm();
  servo_find.write(90);                                  
  delay(700);
  return;
}
// end function
