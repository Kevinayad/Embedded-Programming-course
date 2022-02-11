// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 3 
// Exercise 4 
// Submission code: ZzO-95 (provided by your TA-s) 
char keys[4][4]={//definiton of all keys
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
void setup()// Initial value setups.
{
  
  Serial.begin(9600);//turning on serial monitor
  pinMode(4, INPUT);//setting pin to input mode
  pinMode(5, INPUT);//setting pin to input mode
  pinMode(6, INPUT);//setting pin to input mode
  pinMode(7, INPUT);//setting pin to input mode
  pinMode(8, INPUT);//setting pin to input mode
  digitalWrite(8,HIGH);//setting row pin to high
  pinMode(9, INPUT);//setting pin to input mode
  digitalWrite(9,HIGH);//setting row pin to high
  pinMode(10, INPUT);//setting pin to input mode
  digitalWrite(10,HIGH);//setting row pin to high
  pinMode(11, INPUT);//setting pin to input mode
  digitalWrite(11,HIGH);//setting row pin to high
}

void loop()//repeat until program stops
{
  keyRec();//calling key recognition method
  delay(100);//allowing one key press in 100ms
}
void keyRec(){
  for (int i=4,c=3;i<8,c>=0;i++,c--){//i loops over column pins and c loops over column key matches
  pinMode(i,OUTPUT);//setting colums to output mode to read their values
    for (int j=8,r=3;j<=11,r>=0;j++,r--){//j iterates over every row element for each interation of loop i and r loops over row elements for matching keys
      if(digitalRead(i)==LOW&&digitalRead(j)==LOW){//if both column and row are low means button is pressed
      Serial.println(keys[r][c]);//print corrusponding key match
      }
    }
         pinMode(i,INPUT);//set back the column pins to input mode
  }

  
}