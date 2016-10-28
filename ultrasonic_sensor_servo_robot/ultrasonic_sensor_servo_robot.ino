#include <NewPing.h> //NewPing_v1.8
#include <Servo.h>

#define TRIGGER_PIN 9
#define ECHO_PIN 8
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
Servo servo1;
Servo servo2;
 
void setup() {
  servo1.attach(10);
  servo2.attach(11);
  Serial.begin(9600);
}
 
void loop() {
  
  int lettura=0;
  lettura=sonar.ping_cm(); //salvo sulla variabile lettura i CM del sensore ultrasuoni
  
  Serial.print(lettura); //stampo i valori sul monitor
  Serial.println("cm"); //stampo i valori sul monitor
  
  if(lettura>20){
    avanti();
  }
  else{
    fermo();
  }
  delay(100);
}

void fermo(){
  servo1.writeMicroseconds(1500); //stop first servo
  servo2.writeMicroseconds(1500); //stop second servo
}


void avanti(){
  servo1.writeMicroseconds(2500); //forward first servo
  servo2.writeMicroseconds(2500); //forward second servo
}


void indietro(){
  servo1.writeMicroseconds(1000); //back first servo
  servo2.writeMicroseconds(1000); //back second servo
}
