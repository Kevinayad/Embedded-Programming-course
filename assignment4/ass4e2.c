// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 4 
// Exercise 2
// Submission code: 532&kLm (provided by your TA-s) 
#include <Servo.h> //include the Servo library 
int servoPin = 3; // declare the Servo pin 
volatile int flag=0;// flag used to trigger the interrupt
Servo Servo1;// Create a servo object 
void setup() { 
  Serial.begin(9600);//start serial port
   Servo1.attach(servoPin); //connect servo motor
  attachInterrupt(digitalPinToInterrupt(servoPin),sec,CHANGE);//include interrupt  on a the servo pin for change happening triggered by sec function
}
void loop(){ // keep code running until ended
  for (int i=0,j=0;i<=360,j<=60;i+=6,j++){//i goes from 0 to 360 degrees and j goes from 0 to 60
    if(i<=180){//if degree less than 180
    Servo1.write(i);//move servo to i degree
    }else{
      Servo1.write(i-180);//if degree over 180 move servo to degree -180 to avoid getting stuck
    }
  
    flag++;//flag increases after each itteration
    if(flag>0){//if flag is over 0 
   Serial.println(j);//print out reffering to time
    }
    delay(1000);//wait 1 sec between itterarions
  }
  
  }
void sec() {//used to trigger flag change
  flag=!flag;//set flag to opposite when called
}