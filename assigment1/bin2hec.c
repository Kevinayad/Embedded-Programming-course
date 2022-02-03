#include<stdio.h>    
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[]){//bin to hex conversion refrence: https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
long binaryval=atoi(argv[1]), hexadecimalval = 0, i = 1, remainder;
int success=0;
if(binaryval==NULL){//used to check for non numeric input
success=1;
}
if(strcmp(argv[1],"-h")==0){//used to check for -h
    printf("please input a bianry value of 8 bits or greater\n");
    success=1;
}
if(success==0){
     while (binaryval != 0){
      remainder = binaryval % 10;
      hexadecimalval = hexadecimalval + remainder * i;
      i = i * 2;
      binaryval = binaryval / 10;
   }
   printf("Equivalent hexadecimal value: 0%lX\n", hexadecimalval);
}
  
   if(success==0){
    return 0;
   }else{//incase of bad value
       printf("error bad value\n");
       return 2;
   }
   //we ran both programs using ./decbin 12 |xargs ./bin2hec on mac
}
