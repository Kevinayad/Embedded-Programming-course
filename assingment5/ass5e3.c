// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 5 
// Exercise 3 
// Submission code: 65709E (provided by your TA-s) 

/* CODE IS MOSTLY REUSED FROM WORKPACKAGE 3 exercise 2 */

long miliVolts; //Variable for mini-volts
long temperature; //Variable for temperature
int celsius = 0; //Variable for celsius
int light = 0; //Variable for light

void setup()//setting up initial values
{
pinMode(A0, INPUT); // Sets the pin to input
pinMode(A1, INPUT); // Sets the pin to input
Serial.begin(9600);
pinMode(2, OUTPUT); // Sets the pin to output
pinMode(3, OUTPUT); // Sets the pin to output
pinMode(4, OUTPUT); // Sets the pin to output
}

void lightFunction(int r1,int r2,int input){//r1 is lower range of temp, r2 is higher range, input is real temp
    if(input<r1){//if under lower range
    digitalWrite(2, HIGH);//blue LED on
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, LOW);//red LED off
    }
    else if(input>r2){//if over higher range
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, HIGH);//red LED on
    }
    else{//if inside range
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
    }
}
void loop()//loop over the arduino program 
{

celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);//data translate to celsius
//celsius=analogRead(A1); //resoures
Serial.println("Templerature :");//Print temperature
Serial.println(celsius);
delay(1000);//makes program wait 1 second


light = analogRead(A0);//reads data from light sensor
Serial.println("Light intensity :");//print light intensity
Serial.println(light);
delay (1000);//makes program wait 1 second
  //int ac=((165-(100-(celsuis+40))*100)/165));

  if(celsius<-12&&light<1){//if temperature less than -12 and light intensity less than 1
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
}else if(celsius<-12&&light>1){//if temperature less than -12 and light intensity over than 1
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, HIGH);//red LED on
}
if(celsius>-12 && celsius<=0){//if temperature within the range
  lightFunction(1,20,celsius);//use function to light up correct light according to real temp and range
}
if(celsius>0 && celsius<=20){//if temperature within the range
  lightFunction(21,60,celsius);//use function to light up correct light according to real temp and range
}
if(celsius>=21&&light<61){//if temperature over 21 and light intensity less than 61
    digitalWrite(2, HIGH);//blue LED on
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, LOW);//red LED off
  }else if(celsius>=21&&light>61){//if temperature over 21 and light intensity greater than 61
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
  }

}