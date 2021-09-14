#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
int count=0;
int i;
for(i=0;i<3;i++){
fork();
sleep(5);
}
}
