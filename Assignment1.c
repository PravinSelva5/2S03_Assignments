/* MvM, 20 Game */

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int  score;   /* Globals */
char in[20];

int user(void)
{
 int i=0;
 while(i!=1 && i!=2){
    printf("We are at %-2d, add 1 or 2 ? ",score);
    fgets(in,10,stdin);
    i=atoi(in);
  };
 return(i);
};

// Given current score return 1 or 2
int computer(void)
{
 //Computer Strategy that was implemented
    int i=0;
    if((score%3)==0){i=i+2;}
    if((score%3)==1){i=i+1;}
    if((score%3)==2){i=i+2;}
    printf("Computer adds %d\n",i);
    return(i);
};


int main(void)
{ 
  int i;
  srand(time(NULL));// Init random   time(NULL) returns the current calendar time
  printf(" Who says 20 first \n \n");
  score=0;
  i=0;
  while(i!=1 && i!=2){
    printf("Who goes first: you=1 computer=2 ? ");
    fgets(in,10,stdin);
    i=atoi(in);
  };
  if(i==2)score=computer();
  while(score <=20){
    score=score+user();
    if(score>=20) {printf(" YOU WIN !!\n ");break;};
    score=score+computer();
    if(score>=20) {printf(" I WIN !! \n ");break;};
 };
return(0);
};
