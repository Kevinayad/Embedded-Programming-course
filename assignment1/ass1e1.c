// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 1 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h> 
int main ()//Main class
{
  int num;//Declarate "num"
  while (1){ //Define infinite loop
  printf("Please, enter interger number from 1 to 5 \n");//Print line
  scanf("%d", &num);//Scan number
  switch(num){//switch statement
    case 1://case
    printf("Your choice number 1 sentence\n"); //Case 1 result
    break;//breaks
    case 2://case
    printf("Your choice number 2 sentence\n"); //Case 2 result
    break;//breaks
    case 3://case
    printf("Your choice number 3 sentence\n"); //Case 3 result
    break;//breaks
    case 4://case
    printf("Your choice number 4 sentence\n"); //Case 4 result
    break;//breaks
    case 5://case
    printf("Your choice number 5 sentence\n"); //Case 5 result
    break;//breaks
    default://if any of this case doesn't works
    printf("Your choice incorrect number. Please, input interger number from 1 to 5\n"); //Expection 
    return 0;//finish loop
  }
  num=0;
 }
}
  