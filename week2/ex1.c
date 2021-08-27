#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int i = INT_MAX;
    float f= FLT_MAX;
    double d= DBL_MAX; 
    printf("Max value of INT is      : %d", i);
    printf("\nMax value of FLOAT is  : %f", f);
    printf("\nMax value of DOUBLE is : %lf", d);
    printf("\nsize of int is    : %lu", sizeof(i));
    printf("\nsize of float is  : %lu", sizeof(f));    
    printf("\nsize of double is : %lu\n", sizeof(d));
    return 0;
}