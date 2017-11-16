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
    wait();
    printf("I am the parent and I'm done waiting. See ya later.");
  }
  if(!f){
    int mypid = getpid();
    int sleepy = (rand() % (20+1-5))+5;
    sleep(sleepy);
    printf("I am a child. My pid number is %d and my nap took %d seconds.", mypid, sleepy);
    
  }
  return 0;
}
    
  
  
