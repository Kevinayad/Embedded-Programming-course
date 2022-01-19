#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    if(argc<2){
        printf("no argument input, please try again with -h");
    } else if(argc>2){
        printf("too many arguments, please try again with -h");
    }else if(strcmp(argv[1],"-h")==0){
        printf("info");
    }else {
        printf("%s",argv[1]);
    }
}