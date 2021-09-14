#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
fork();
fork();
fork();
fork();
fork();
sleep(5);
   return EXIT_SUCCESS;
}

