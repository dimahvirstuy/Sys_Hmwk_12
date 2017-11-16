#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int PID = getpid();
  printf("This is the initial statement\n");
  int f=fork();
  if(f){
    fork();
    int * status = wait();
  }
  if(!f){
    sleep((rand() % (20+1-5))+5;);
  }
 
    
    
  
  
