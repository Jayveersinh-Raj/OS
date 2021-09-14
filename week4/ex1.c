#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
int n=1;
 pid_t c=fork();
    if(c == 0)  // fork returns 0 to the child process so it enters "if" block
    {
        printf("Hello from son [%d]\n",getpid()-n); 
      
    }
    if(c==1) //Fork returns 1 to the parent process and enters this bolck
    {
     printf("Hello from parent [%d]\n",getpid()-n); 
    }
 else{
  printf("There is an error unfortunately");
  exit(0);
 }
}
