#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]){
    int sum=0;//used to sum status
    char engine_on;//values for printing later on
    char gear_pos;
    char key_pos;
    char brake1;
    char brake2;
if((argv[1][0]>=65&&argv[1][0]<71)||(argv[1][0]>=48&&argv[1][0]<58)){//check that first input is between 0 and 4 or 8 or 9 or between A and C
    if(argv[1][0]==53||argv[1][0]==54||argv[1][0]==55||argv[1][0]==68||argv[1][0]==69||argv[1][0]==70||strlen(argv[1])>2){//shouldnt match those values since they fail later on
        printf("input cannot match gear position\n");
    }else{
    sum++;
    }
    
}
if((argv[1][1]>=65&&argv[1][1]<71)||(argv[1][1]>=48&&argv[1][1]<58)){
    if(argv[1][1]==67||argv[1][1]==68||argv[1][1]==69||argv[1][1]==70){
        printf("input cannot match key position\n");
    }else{
    sum++;
    }
}
if(argc==2&&sum==2){
    switch(argv[1][1]){
        case '0':
        key_pos='0';
        brake1='0';
        brake2='0';
        break;
        case '1':
        key_pos='0';
        brake1='0';
        brake2='1';
        break;
        case '2':
        key_pos='0';
        brake1='1';
        brake2='0';
        break;
        case '3':
        key_pos='0';
        brake1='1';
        brake2='1';
        break;
        case '5':
        key_pos='1';
        brake1='0';
        brake2='1';
        break;
        case '6':
        key_pos='1';
        brake1='1';
        brake2='0';
        break;
        case '7':
        key_pos='1';
        brake1='1';
        brake2='1';
        break;
        case '8':
        key_pos='2';
        brake1='0';
        brake2='0';
        break;
        case '9':
        key_pos='2';
        brake1='0';
        brake2='1';
        break;
        case 'A':
        key_pos='2';
        brake1='1';
        brake2='0';
        break;
        case 'B':
        key_pos='2';
        brake1='1';
        brake2='1';
        break;

    }
    switch(argv[1][0]){
        case '0':
        engine_on='0';
        gear_pos='0';
        break;
        case '1':
        engine_on='0';
        gear_pos='1';
        break;
        case '2':
        engine_on='0';
        gear_pos='2';
        break;
        case '3':
        engine_on='0';
        gear_pos='3';
        break;
        case '4':
        engine_on='0';
        gear_pos='4';
        break;
        case '8':
        engine_on='1';
        gear_pos='0';
        break;
        case '9':
        engine_on='1';
        gear_pos='1';
        break;
        case 'A':
        engine_on='1';
        gear_pos='2';
        break;
        case 'B':
        engine_on='1';
        gear_pos='3';
        break;
        case 'C':
        engine_on='1';
        gear_pos='4';
        break;

    }
    printf("Name\t\t\t Value\n");
    printf("--------------------------------------\n");
    printf("engine_on\t\t %c\n",engine_on);
    printf("gear_pos\t\t %c\n",gear_pos);
    printf("key_pos\t\t\t %c\n",key_pos);
    printf("brake1\t\t\t %c\n",brake1);
    printf("brake2\t\t\t %c\n",brake2);
}else{
    printf("error too many or too few arguemnts or bad input\n");
}
return 0;
}
//65 70
//48 57