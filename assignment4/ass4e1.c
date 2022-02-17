long miliVolts;
int celsius = 0;
volatile int flag=0;

void setup()//setting up initial values
{
pinMode(A1, INPUT);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(A1),sec,CHANGE);//interupt declaration
}

void loop()//loop over the arduino program 
{

flag++;
if(flag>0){ //interupt

float voltage = (analogRead(A1) * (5.0 / 1023.0)) * 1000;//data translate to voltage.
//https://www.arduino.cc/en/Tutorial/BuiltInExamples/ReadAnalogVoltage 
int celsius = (voltage - 500) / 10;//this formula was taken from WP3 Exercise 3
Serial.println("Templerature :");//Print temperature
Serial.println(celsius);
delay(1000);//makes program wait 1 second

if(celsius<=0){//if temperature lower than 0
    digitalWrite(6, LOW);//LED 1 off
    digitalWrite(2, LOW);//LED 2 off
    digitalWrite(3, LOW);//LED 3 off
    digitalWrite(4, LOW);//LED 4 off
    digitalWrite(5, LOW);//LED 5 off
}
if(celsius>0&&celsius<10){//if temperature lower than 10 but higher than 1
    digitalWrite(6, HIGH);//LED 1 on
    digitalWrite(2, LOW);//LED 2 off
    digitalWrite(3, LOW);//LED 3 off
    digitalWrite(4, LOW);//LED 4 off
    digitalWrite(5, LOW);//LED 5 off

}
if(celsius>11&&celsius<20){//if temperature lower than 20 but higher than 11
    digitalWrite(6, HIGH);//LED 1 on
    digitalWrite(2, HIGH);//LED 2 on
    digitalWrite(3, LOW);//LED 3 off
    digitalWrite(4, LOW);//LED 4 off
    digitalWrite(5, LOW);//LED 5 off
}
if(celsius>21&&celsius<30){//if temperature lower than 30 but higher than 21
    digitalWrite(6, HIGH);//LED 1 on
    digitalWrite(2, HIGH);//LED 2 on
    digitalWrite(3, HIGH);//LED 3 on
    digitalWrite(4, LOW);//LED 4 off
    digitalWrite(5, LOW);//LED 5 off
}
if(celsius>31&&celsius<40){//if temperature lower than 40 but higher than 31
    digitalWrite(6, HIGH);//LED 1 on
    digitalWrite(2, HIGH);//LED 2 on
    digitalWrite(3, HIGH);//LED 3 on
    digitalWrite(4, HIGH);//LED 4 on
    digitalWrite(5, LOW);//LED 5 off
}
if(celsius>41&&celsius<50){//if temperature lower than 50 but higher than 41
    digitalWrite(6, HIGH);//LED 1 on
    digitalWrite(2, HIGH);//LED 2 on
    digitalWrite(3, HIGH);//LED 3 on
    digitalWrite(4, HIGH);//LED 4 on
    digitalWrite(5, HIGH);//LED 5 on
}
}
}
void sec(){//function which reverse value
flag=!flag;
}