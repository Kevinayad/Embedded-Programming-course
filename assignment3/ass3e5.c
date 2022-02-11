// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 3 
// Exercise 5 
// Submission code: ZzO-95 (provided by your TA-s) 
#include<Keypad.h>
char keys[4][4]={//definiton of all keys
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rows[4]={7,6,5,4};//definition of row pins
byte cols[4]={11,10,9,8};//defnition of column pins
Keypad keyMap=Keypad(makeKeymap(keys),cols,rows,4,4);//keypad setup
void setup()// Initial value setups.
{
  
  Serial.begin(9600);//turning on serial monitor
  
}

void loop()//repeat until program stops
{
  char key=keyMap.getKey();//new keypad instance
  if(key){//if key matches keys array
  Serial.println(key);//print key to serial monitor
  }
}



