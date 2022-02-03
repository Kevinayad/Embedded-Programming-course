// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 1 
// Exercise 1 
// Submission code: ATb-Fc1 (provided by your TA-s) 

#include <stdio.h> 
int main ()//Main class
{
  int num;//Declarate "num"
  while (1)
  { //Define infinite loop
  printf("Please, enter interger number from 1 to 5 \n");//Print line
  scanf("%d", &num);//Scan number
  if(num==1)//If the user entered number 1
  {
    printf("You entered 1\n");
  }
  else if(num==2)//If the user entered number 2
  {
    printf("You entered 2\n");
  }
  else if(num==3)//If the user entered number 3
  {
    printf("You entered 3\n");
  }
  else if(num==4)//If the user entered number 4
  {
    printf("You entered 4\n");
  }
  else if(num==5) //If the user entered number 5
  {
    printf("You entered 5\n");
  }
  else //If the user entered wrong number or any character
  {
    printf("You entered wrong number or character.\n");
    return 0;//without this line , code will run endlessly 
  }
 }
}
  