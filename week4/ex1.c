#include<unistd.h>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
int n=1;
 pid_t c=fork();
    if(c == 0)  // fork returns 0 to the child process so it enters "if" block
    {
        printf("[son] pid %d from [parent] pid %d\n",getpid()-n,getpid()-n); 
        // child exits
        exit(0);
    }
}
