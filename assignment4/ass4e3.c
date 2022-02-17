// Kevin, Enis, Vlad, group: 26 532&kLm (2022) 
// Work package 4 
// Exercise 3
// Submission code: ZzO-95 (provided by your TA-s) 


#include <Adafruit_NeoPixel.h> // Imports the NeoPixel library.

#define PIN            9 // Pin for Neopixel input
#define LED_PIN        2 // Red-LED Pin
#define NUM_OF_PIXELS      12 // Number of pixels in Neopixel
#define sensorPin A0 // Tempreture sensor pin
int lightsOn; // Number of lights turned on in Neopixel.

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800); // Creating Neopixel object to use functions from library on the object.

void setup() { // Setting up inital values.
  Serial.begin(9600); // // Starting serial communication.
  pixels.begin(); // Initialize neopixel object.
  pixels.setBrightness(100); // Sets pixel brightness.
  pixels.show(); // Updates the pixel object to the latest state.
  pinMode(sensorPin, INPUT);
}

void loop() { // Arduino loop that keeps running until program is exited.
  uint32_t green = pixels.Color(0, 255, 0); // Green light.
  float voltage = analogRead(sensorPin) * (5.0 / 1023.0); // Reading voltage from sensorPin.
  int celsius = (voltage - 0.5) * 100; // Calculating celsius from voltage. https://forum.arduino.cc/t/project-3-cant-understand-voltage-to-temperature-formula/246851
  lightsOn = (abs(celsius +40) - abs(celsius +40) %10) / 10; /* Calculates the number of celsius starting from -40 to 160. 
                                                                The number is floored to the nearest full complete ten number. 
                                                                Every light in the Neopixel represents 
                                                                10 celsius. When the full ring lights up
                                                                it means that the temperature has reached
                                                                80 celsius and the red led is also turned on.*/
  
  for (int i = 0; i < lightsOn; i++) { // Loops from 0 to the number of lightsOn.
    pixels.setPixelColor(i, green); // Turns the light at index 0 to green.
    pixels.show(); // Updates the pixel object to the latest state.
  }
  
  for (int i = lightsOn; i < NUM_OF_PIXELS; i++) { // Loops from lightsOn to NUM_OF_PIXELS to turn of any lights thats still on from the last loop.
    pixels.setPixelColor(i, 0,0,0); // Turns of the lights at index i.
    pixels.show(); // Updates the pixel object to the latest state.
  }
  
  if (lightsOn >= 12) { // If the lightsOn is greater than or equal to 12 all of the neopixels lights are on and we need to turn on the red led.
	  digitalWrite(LED_PIN, HIGH); // Turns on the red led.
  } else { // If lightsOn is less than 12 we need to make sure the red led is turned off.
  	  digitalWrite(LED_PIN, LOW); // Turns off the red led.
  }
  delay(50); // Makes the loop wait for 50ms before the next iteration.
}