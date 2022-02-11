// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 3 
// Exercise 3 
// Submission code: ZzO-95 (provided by your TA-s) 
#define sensorPin A0 // Pin that tempreature sensor is connected to.


void setup() // Initial value setups.
{
  Serial.begin(9600); // Starts serial communication for the arduino.
  pinMode(sensorPin, INPUT); // Sets the sensor pin to behave as a input pin.
}

void loop() // Loops over the program to actively control the board.
{
  float voltage = (analogRead(sensorPin) * (5.0 / 1023.0)) * 1000; // Calculates the voltage from the analogread value. https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage
  int celsius = (voltage - 500) / 10; // minivolts to celsius formula according to the assignment.
  									   
  Serial.println(celsius); // Prints the calculated celsius temperature.
  delay(500); // Makes the loop wait 0.5 seconds before continuing to next iteration.
}

