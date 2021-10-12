#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
int size=10*1024*1024; //storing 10mb by converting to bytes
int *ptr; 
int i;
for(i=0;i<9;i++){
ptr=malloc(size); //To assign 10 mb of space
memset(ptr,0,size);
free(ptr);
}
}
//The size of my RAM is larger and swap sapce alloacted is lower
// so my swap value keeps showing 0. By changing settings, the change
// can be seen while the virtual memory is being allocated
