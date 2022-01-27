#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])//Main class
{
    int first,second;//Declarate "first" "second"
    int ROT = atoi(argv[1]);//Define "ROT"

    while((first=getchar())!=EOF)//Loop for all letters
    {
        if(first >='A' && first <='Z')//Loop for capital letters
    {
        {
            if((second = first + ROT) <= 'Z')//If letter stand before Z order
                putchar(second);
            else
            {
                   second = first - ROT;//If character stand before Z order
                putchar(second);
            }
        }
        else if(first >='a' && first <='z')//Loop for lower letters
    {
        {
            if((second= first + ROT) <= 'z')//If letter stand before Z order
                putchar(second);
            else
            {
                second = first - ROT;//If character stand before Z order
                putchar(second);//print result
            }
        }
        else
            putchar(first);//If none of this works 
    }
return 0;
}