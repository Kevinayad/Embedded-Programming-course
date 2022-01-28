#include<stdio.h>    
#include<math.h>
#include<string.h>
#include<stdlib.h>
long numBase(long input){//this function returns the base of the number in 10s
    int i=10;
    int c=1;
    int state=0;
do{
if(i>=input){
return c;
state=1;
}else{
    i=i*10;
    c++;
}
}while(state!=1);
}
int checkPwr2(int input)//this function checks if a number is a power of 2 
//refrence:https://www.geeksforgeeks.org/c-program-to-find-whether-a-no-is-power-of-two/
{
    if (input == 0)
        return 0;
    while (input != 1) {
        if (input % 2 != 0)
            return 0;
        input = input / 2;
    }
    return 1;
}
int main(int argc,char *argv[]){  
int success;//state of input
long input = atoi(argv[1]);//save as long
if(strcmp(argv[1],"-h")==0){//checks for -h
    printf("please enter a decimal number\n");
}
 if(input==NULL||strcmp(argv[1],"-h")==0){//checks for false inputs
     success=0;
}else{
    success=1;
}
if(success!=0){//only apply if successful
int base=pow(2,numBase(input));//base power of 2
while(checkPwr2(base)!=1||base<8){//8 bits atleast att all times
    base++;
}
long table[base];//convertion table
long result[base];//reveresed result array
long res[base];//true result array
for(int i= 0;i<base;i++){//generate convertion table
    table[i]=pow(2,i);

}
for(int i=base-1;i>=0;i--){//save results in result array
    if((input-table[i])>=0){
        input=input-table[i];
        result[i]=1;
        
    }else{
        result[i]=0;
        
    }
}
for(int i=base-1,j=0;i>=0,j<base;i--,j++){//reverse right result
    res[j]=result[i];
    
}
for(int i=0;i<base;i++){//print result
    printf("%d",res[i]);
}
printf("\n");

}
if(success==1){//if succesful return 0 otherwise return 2
return 0;  
}
else{
    printf("failure please try -h\n");
return 2;
}
}  