// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 3; 
volatile int flag=0;
// Create a servo object 
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
  Serial.begin(9600);
   Servo1.attach(servoPin); 
  attachInterrupt(digitalPinToInterrupt(servoPin),sec,CHANGE);
}
void loop(){ 
  for (int i=0;i<=360;i+=6){
  Servo1.write(i);
    flag++;
   // Serial.println(flag);
    if(flag>0){
   Serial.println(i/6);
    }
    //Serial.println(_timer1);
    delay(1000);
  }
  
  }
void sec() {
  flag=!flag;
  //Serial.println(flag);
}