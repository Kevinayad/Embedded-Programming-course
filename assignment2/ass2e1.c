// Kevin, Enis, Vlad, group: 26 __ (2022) 
// Work package 2
// Exercise 1 
// Submission code: ?D59Cd (provided by your TA-s)
#include<stdio.h>
#include<string.h>
    enum DIRECTION {N,O,S,W}; //Direction list
 
typedef struct { //define ROBOT
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT; 
void move(int *x,int *y,enum DIRECTION dir){//move axis one step forward
if(*y>=0&&*y<99&&dir==N){
    *y=*y+1;
}else if(*y>=0&&*y<99&&dir==S){
    *y=*y-1;
}else if(*x>=0&&*x<99&&dir==W){
    *x=*x-1;
}else if(*x>=0&&*x<99&&dir==O){
    *x=*x+1;
}else{
    printf("cannot add anymore steps\n");
}
}
void turn(int *c){//turn the direction
    if(*c>=0||*c<4){
        *c=*c+1;
    }else{
        *c=0;
    }
    
}
//used to get value from enum
const char* getDirName(enum DIRECTION dir) //refrence:https://stackoverflow.com/questions/3168306/print-text-instead-of-value-from-c-enum
{
   switch (dir) 
   {
      case N: return "N";
      case O: return "O";
      case S: return "S";
      case W: return "W";
      /* etc... */
   }
}


int main(){
   ROBOT R1;//robot instance
    char choice;//char to choose from
    enum DIRECTION dir=N;//default direction and direction variable
    int c=0;//counter
    do{//keep asking for x and y axis if not between 0 and 99
    printf("please input the starting position x coordinate between 0 and 99: \n");
    scanf("%d",&R1.xpos);
    }while(R1.xpos<0||R1.xpos>99);
    do{
    printf("please input the starting position y coordinate between 0 and 99: \n");
    scanf("%d",&R1.ypos);
    }while(R1.ypos<0||R1.ypos>99);
    printf("enter m to move one step forward, enter t to to turn directions, enter e to finalize\n");//instructions
    while(choice!='e'){//keep repeating if user doesnt want to end
         
         scanf(" %c",&choice);//get choice from user
         if(choice=='m'){//if m move 1 step
             move(&R1.xpos,&R1.ypos,dir);
             
          }else if(choice=='t'){//if t turn direction
              turn(&c);//save in c
              for(R1.dir= N; R1.dir<=W;R1.dir++){//loop through enum
                   if(R1.dir==c){//set value to variable if match
                       dir=R1.dir;
                   }
              }
          }
        
    
    printf("X coordinate: %d Y coordinate: %d Direction: %s\n",R1.xpos,R1.ypos,getDirName(dir));//result
    }
    printf("Goodbye!\n");
    return 0;
}