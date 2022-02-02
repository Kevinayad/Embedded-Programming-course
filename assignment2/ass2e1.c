#include<stdio.h>
#include<string.h>
    enum DIRECTION {N,O,S,W}; 
 
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 
void move(int *x){
if(*x>=0&&*x<99){
    *x=*x+1;
}else{
    printf("cannot add anymore steps\n");
}
}
void turn(int *c){
    if(*c>=0||*c<4){
        *c=*c+1;
    }else{
        *c=0;
    }
    
}
int main(){
   ROBOT R1;
    char choice;
    R1.dir=0;
    int c=0;
    do{
    printf("please input the starting position x coordinate between 0 and 99: \n");
    scanf("%d",&R1.xpos);
    }while(R1.xpos<0||R1.xpos>99);
    do{
    printf("please input the starting position y coordinate between 0 and 99: \n");
    scanf("%d",&R1.ypos);
    }while(R1.ypos<0||R1.ypos>99);
    //printf("%d %d",R1.xpos,R1.ypos);
    while(choice!='e'){
         printf("enter m to move one step forward, enter t to to turn directions, enter e to finalize\n");
         scanf(" %c",&choice);
         //getchar(choice);
         printf("%c",choice);
         if(choice=='m'){
             move(&R1.xpos);
             
          }else if(choice=='t'){
              turn(&c);
              printf("%d\n",c);
              for(R1.dir= N; R1.dir<=W;R1.dir++){
                  printf("%d\n",R1.dir);
                   if(c==R1.dir){
                       R1.dir=c;
                   }
              }
          }
        
    
    
    }
    printf("%d %d %d",R1.xpos,R1.ypos,R1.dir);
    return 0;
}