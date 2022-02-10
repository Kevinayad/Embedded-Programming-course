long miliVolts;
long temperature;
int celsius = 0;
int light = 0;

void setup()//setting up wires for components
{
pinMode(A0, INPUT);
pinMode(A1, INPUT);
Serial.begin(9600);//begin serial port
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
}

void loop()//main code
{

celsius = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);//data translate to celsius
//celsius=analogRead(A1);
Serial.println("Templerature :");//Print temperature
Serial.println(celsius);
delay(1000);//makes program wait 1 second


light = analogRead(A0);//reads data from light sensor
Serial.println("Light intensity :");//print light intensity
Serial.println(light);
delay (1000);//makes program wait 1 second

  //int ac=((165-(100-(celsuis+40))*100)/165));

  if(celsius<-12&&(light>=0&&light<=1)){//if temperature lower than should be
    digitalWrite(2, HIGH);//blue LED on
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, LOW);//red LED off
}else if((celsius>-12 celsius<=0)&&(light>1&&light<=20)){//if temperature within the range
  digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
}else if((celsius>0 celsius<=20)&&(light>21&&light<=60)){//if temperature within the range
  digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
}else if((celsius>=21)&&(light>61&&light<=100)){//if temperature higher than should be 
  digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, HIGH);//red LED on
  }


}