#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
pid_t pid = fork();
   if (pid == -1) {
      perror("fork failed");
      exit(EXIT_FAILURE);
   }
   else if (pid == 0) { 
fork();
fork();
fork();
fork();
fork();
sleep(5);
      _exit(EXIT_SUCCESS);
   }
   else {
      int status;
      waitpid(pid, &status, 0);
   }
   return EXIT_SUCCESS;
}

