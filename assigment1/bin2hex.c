#include<stdio.h>    
#include<math.h>
#include<string.h>
#include<stdlib.h>
int total(char inp,int c, int t){
    if(c==0&&inp=="1"){
            t=t+8;
        }else if(c==1&&inp=="1"){
            t=t+4;
        }else if(c==2&&inp=="1"){
            t=t+2;
        }else if(c==3&&inp=="1"){
            t=t+1;
        }
        if(c==4){
            c=0;
        } 
        return t;
}
void output(int t){
    if(t>=0&&t<=9){
        printf("%d",t);
    }else if(t==10){
        printf("A");
    }else if(t==11){
        printf("B");
    }else if(t==12){
        printf("C");
    }else if(t==13){
        printf("D");
    }else if(t==14){
        printf("E");
    }else if(t==15){
        printf("D");
    }
}
int main(int argc,char *argv[]){
    //int input=strlen(argv[1]);
    int c=0,t=0;
    //char inp=argv[1];
    //printf("%c",inp);
    for(int i=0;i<strlen(argv[1]);i+=4){
        //printf("%d ",i);
    for(int j=i;j<i+4;j++){
        
            total(argv[1][j],c,t);
            printf("%d",t);
            if(c==3){
                output(t);
            }
            //printf("%d",c);
            c++;
            
        }
        c=0;
        t=0;
    }
        
        // if(c==0&&argv[1][i]=="1"){
        //     t=t+8;
        // }else if(c==1&&argv[1][i]=="1"){
        //     t=t+4;
        // }else if(c==2&&argv[1][i]=="1"){
        //     t=t+2;
        // }else if(c==3&&argv[1][i]=="1"){
        //     t=t+1;
        // } 
   // }    
    // if(t>=0&&t<=9){
    //     printf("%d",t);
    // }else if(t==10){
    //     printf("A");
    // }else if(t==11){
    //     printf("B");
    // }else if(t==12){
    //     printf("C");
    // }else if(t==13){
    //     printf("D");
    // }else if(t==14){
    //     printf("E");
    // }else if(t==15){
    //     printf("D");
    // }
    // }
}
