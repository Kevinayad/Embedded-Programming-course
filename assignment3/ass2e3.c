#define sensorPin A0 // Pin that tempreature sensor is connected to.


void setup() // Initial value setups.
{
  Serial.begin(9600); // Starts serial communication for the arduino.
  pinMode(sensorPin, INPUT); // Sets the sensor pin to behave as a input pin.
}

void loop() // Loops over the program to actively control the board.
{
  float voltage = analogRead(sensorPin) * (5.0 / 1023.0); // Calculates the voltage from the analogread value.
  int celsius = (voltage - 0.5) * 100; // Voltage to celsius formula https://forum.arduino.cc/t/project-3-cant-understand-voltage-to-temperature-formula/246851
  									   // Formula provided by assignment gives wrong values.
  										// Temperature (°C) = (VOUT – 500) / 10
  Serial.println(celsius); // Prints the calculated celsius temperature.
  delay(500); // Makes the loop wait 0.5 seconds before continuing to next iteration.
}
