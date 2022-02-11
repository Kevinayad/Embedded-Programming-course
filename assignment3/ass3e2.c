
long miliVolts;
long temperature;
int celsius = 0;
int light = 0;

void setup()//setting up initial values
{
pinMode(A0, INPUT);
pinMode(A1, INPUT);
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
}

void lightFunction(int r1,int r2,int input){
    if(input<r1){
    digitalWrite(2, HIGH);//blue LED on
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, LOW);//red LED off
    }
    else if(input>r2){
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, HIGH);//red LED on
    }
    else{
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

  if(celsius<-12&&light<1){//if temperature lower than should be
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
}else if(celsius<-12&&light>1){
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, HIGH);//red LED on
}
if(celsius>-12 celsius<=0){//if temperature within the range
  lightFunction(1,20,celsius);
}
if(celsius>0 celsius<=20){//if temperature within the range
  lightFunction(21,60,celsius);
}
if(celsius>=21&&light<61){//if temperature higher than should be 
    digitalWrite(2, HIGH);//blue LED on
    digitalWrite(3, LOW);//green LED off
    digitalWrite(4, LOW);//red LED off
  }else if(celsius>=21&&light>61){
    digitalWrite(2, LOW);//blue LED off
    digitalWrite(3, HIGH);//green LED on
    digitalWrite(4, LOW);//red LED off
  }

}