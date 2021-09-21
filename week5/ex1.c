#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *printMessage(void *x){
long *id= (long *)x;
printf("Hello, this is thread %ld\n",*id);
pthread_exit(NULL);
}
int main(int argc, char *argv[]){
int n=3;

if(argc == 2){
n = strtol(argv[1], NULL, 10);
}

int i;
for(i=0;i<3;i++){
pthread_t t0;
pthread_create(&t0,NULL,printMessage,(void*)t0);
printf("Thread %d created \n",i+1);
}
}
