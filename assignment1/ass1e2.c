// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 1 
// Exercise 2 
// Submission code: ATb-Fc1 (provided by your TA-s) 
// Limitations: use only English alphabet letters (capital of lowercase)
#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])//Main class
{
    int first,second;//Declarate "first" "second"
    int ROT = atoi(argv[1]);//Define "ROT"
    
    while((first=getchar())!=EOF)//Loop for all letters
    {
         if(first >=65 && first <=90)//If the letter is capital
         {
            if((second = first + ROT) <= 90)//If letter "second" stand before Z order
                putchar(second);
            else
            {
                second = first - ROT ;//If letter "second" stand after Z order
                putchar(second);
            }
         }
     
         else if(first >=97 && first <=122)//If the letter is lowercase
         {
            if((second= first + ROT) <= 122)//If letter "second" stand before Z order
                putchar(second);
            else
            {
                second = first - ROT;//If letter "second" stand after Z order
                putchar(second);
            }
         }
         else{
             putchar(first);
         }
      }
return 0;
}
