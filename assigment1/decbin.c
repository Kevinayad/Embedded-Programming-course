#include<stdio.h>    
#include<math.h>
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
//printf("%ld",numBase(11));
long input = atoi(argv[1]);//save as int
int base=pow(2,numBase(input));//base power of 2
while(checkPwr2(base)!=1||base<8){//8 bits atleast att all times
    base++;
}
//printf("%d\n",base);
int table[base];//convertion table
int result[base];//result array
for(int i= 0;i<base;i++){//generate convertion table
    table[i]=pow(2,i);
    //printf("%d\n",table[i]);
}
for(int i=base-1;i>=0;i--){//save results in result array
    if((input-table[i])>=0){
        input=input-table[i];
        result[i]=1;
        //strcat(&result[i],"1");
    }else{
        result[i]=0;
        //strcat(&result[i],"0");
    }
}
for(int i=base-1;i>=0;i--){//print result array
    printf("%d",result[i]);
}
//printf("%ld",base);
return 0;  
}  