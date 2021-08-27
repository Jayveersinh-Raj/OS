#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char *argv[])
{
    int i,j;
    int n= atoi(argv[1]);
if(argc<= 1){
printf("Enter the arguent");
}
else{
    for (i = 0; i < n ; i++)
    {
        for (j = 1; j < 2*n-1; j++)
        {
            if(j>=n-(i-1)&&j<=n+(i-1)){
                printf("*");
            }
            else {
                printf(" ");
            }
        }
                printf("\n");
    }
  return 0;
}
}
