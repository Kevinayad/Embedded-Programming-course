#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    int status[5];//status array for all arguments
    int sum=0;//used to add sum of status
    unsigned char result[8];//save result
    if(argc==6){
        if((atoi(argv[1])>=0&&atoi(argv[1])<=9)&&(argv[1][0]>=48&&argv[1][0]<50)){//check if first argument is between 0 and 1
         status[0]=1;
     }else{
         status[0]=0;
     }

     if((atoi(argv[2])>=0&&atoi(argv[2])<=9)&&(argv[2][0]>=48&&argv[2][0]<53)){//check if second argument is between 0 and 4
         
         status[1]=1;
     }else{
         status[1]=0;
     }

     if((atoi(argv[3])>=0&&atoi(argv[3])<=9)&&(argv[3][0]>=48&&argv[3][0]<51)){//check if third argument is between 0 and 2
        
         status[2]=1;
     }else{
         status[2]=0;
     }

     if((atoi(argv[4])>=0&&atoi(argv[4])<=9)&&(argv[4][0]>=48&&argv[4][0]<50)){//check if fourth argument is between 0 and 1
         
         status[3]=1;
     }else{
         status[3]=0;
     }

     if((atoi(argv[5])>=0&&atoi(argv[5])<=9)&&(argv[5][0]>=48&&argv[5][0]<50)){//check if fifth argument is between 0 and 1
         
         status[4]=1;
     }else{
         status[4]=0;
     }
     for(int i=0;i<5;i++){//make sure all status are ok and add to sum
         if(status[i]==1)
         sum=sum+status[i];
     }

    }else{
        printf("too few or too many arguments\n");//if too little or too many inputs print error message 
    }
     
if (argc==6){//check correct amount of arguemnts and all arguemnts are correct
if(sum==5){
switch(atoi(argv[1])){//put result in binary for argument 1 in result array
        result[0]='0';
        break;
        case 1:
        result[0]='1';
        break;
    }
    switch(atoi(argv[2])){//put result in binary for argument 2 in result array
        case 0:
        result[1]='0';
        result[2]='0';
        result[3]='0';
        break;
        case 1:
        result[1]='0';
        result[2]='0';
        result[3]='1';
        break;
        case 2:
        result[1]='0';
        result[2]='1';
        result[3]='0';
        break;
        case 3:
        result[1]='0';
        result[2]='1';
        result[3]='1';
        break;
        case 4:
        result[1]='1';
        result[2]='0';
        result[3]='0';
        break;
    }
    switch(atoi(argv[3])){//put result in binary for argument 3 in result array
        case 0:
        result[4]='0';
        result[5]='0';
        break;
        case 1:
        result[4]='0';
        result[5]='1';
        break;
        case 2:
        result[4]='1';
        result[5]='0';
        break;
    }
    switch(atoi(argv[4])){//put result in binary for argument 3 in result array
        case 0:
        result[6]='0';
        break;
        case 1:
        result[6]='1';
        break;
    }
    switch(atoi(argv[5])){//put result in binary for argument 4 in result array
        case 0:
        result[7]='0';
        break;
        case 1:
        result[7]='1';
        break;
    }
    long int binaryval, hexadecimalval = 0, i = 1, remainder; //refrence: https://www.tutorialspoint.com/how-to-convert-binary-to-hex-by-using-c-language
    binaryval=atol(result);
   while (binaryval != 0){
      remainder = binaryval % 10;
      hexadecimalval = hexadecimalval + remainder * i;
      i = i * 2;
      binaryval = binaryval / 10;
   }
   printf("%lX\n", hexadecimalval);
}else{
    printf("incorrect input\n");//error message
}   
}
}