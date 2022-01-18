//Arduino Human Following Robot
// Created By DIY Builder
// You have to Install the AFMotor and NewPing library Before Uploading the sketch//
// To install the libraries ( first download the AF Motor driver, NewPing and Servo Library zip file //
// then Go to Skecth >> Include Library >> Add .Zip Library >> Select The downloaded zip file >> Done) //
// Contact me on instagram for any question(Insta Id : DIY.Builder)


#include<NewPing.h>
#include<AFMotor.h>
#define RIGHT A2
#define LEFT A3
#define TRIGGER_PIN A1
#define ECHO_PIN A0
#define MAX_DISTANCE 100
  

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RIGHT, INPUT);
  pinMode(LEFT, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(50);
  unsigned int distance = sonar.ping_cm();
  Serial.print("distance");
  Serial.println(distance);


  int Right_Value = digitalRead(RIGHT);
  int Left_Value = digitalRead(LEFT);

  Serial.print("RIGHT");
  Serial.println(Right_Value);
  Serial.print("LEFT");
  Serial.println(Left_Value);

if((Right_Value==1) && (distance>=10 && distance<=30)&&(Left_Value==1)){
  Motor1.setSpeed(120);
  Motor1.run(FORWARD);
  Motor4.setSpeed(120);
  Motor4.run(FORWARD);
}else if((Right_Value==0) && (Left_Value==1)) {
  Motor1.setSpeed(200);
  Motor1.run(FORWARD);
  Motor4.setSpeed(100);
  Motor4.run(BACKWARD);
}else if((Right_Value==1)&&(Left_Value==0)) {
  Motor1.setSpeed(100);
  Motor1.run(BACKWARD);
  Motor4.setSpeed(200);
  Motor4.run(FORWARD);
}else if((Right_Value==1)&&(Left_Value==1)) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
}else if(distance > 1 && distance < 10) {
  Motor1.setSpeed(0);
  Motor1.run(RELEASE);
  Motor4.setSpeed(0);
  Motor4.run(RELEASE);
  }
 }
