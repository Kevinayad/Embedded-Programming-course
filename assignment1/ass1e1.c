// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 1 
// Exercise 1 
// Submission code: XXXXXX (provided by your TA-s) 

#include <stdio.h> 
int main ()
{
  int num;

//Printing whitch 
  printf("Please, enter interger number from 1 to 5 \n");
  scanf("%d", &num);

//Creating switch statement
  switch(num){
    
    case 1:
    printf("Your choice number 1 sentence"); //Case 1 result
    break;
    case 2:
    printf("Your choice number 2 sentence"); //Case 2 result
    break;
    case 3:
    printf("Your choice number 3 sentence"); //Case 3 result
    break;
    case 4:
    printf("Your choice number 4 sentence"); //Case 4 result
    break;
    case 5:
    printf("Your choice number 5 sentence"); //Case 5 result
    break;
    default:
    printf("Your choice incorrect number. Please, input interger number from 1 to 5"); //Expection 
    break;
  }
  return 0;
}
  