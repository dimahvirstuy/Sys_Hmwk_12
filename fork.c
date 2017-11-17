#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
  int status;
  srand(time(NULL));
  int PID = getpid();
  printf("Hi I'm the parent, my pid number is %d,\n", PID);
  pid_t f=fork();
  int kid_pid;
  if(f){ // if its the parent
    kid_pid = wait(&status);
  }
  if(!f){
    int mypid = getpid();
    int sleepy = rand()%16 + 5;
    printf("I am child %d and I am going to sleep for %d seconds\n", mypid, sleepy);
    sleep(sleepy);
    printf("I am child %d and I woke up from nap.\n", mypid);
    exit(sleepy); 
  }
  else {
    printf("I'm the parent and my child %d napped for %d secs \n", kid_pid, WEXITSTATUS(status));
    printf("I'm the parent and I'm done with the program, bye!\n");
  }
  return 0;
}
    
  
  
