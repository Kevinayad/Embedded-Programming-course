// C++ code
//
void setup()
{
  pinMode(12, OUTPUT);//set pin for output
  pinMode(13, OUTPUT);//set pin for output
}

void loop()
{
digitalWrite(12,HIGH);//set pin 12 to high(on)
digitalWrite(13,HIGH);//set pin 13 to high(on)
delay(1000);//wait 1 second
digitalWrite(13,LOW);//turn off pin 13
delay(1000);//wait 1 second
}