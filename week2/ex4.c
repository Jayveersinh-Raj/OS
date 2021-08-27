#include <stdio.h>

void swap(int *x, int *y)
{
	int t = *xp;
	*x = *y;
	*y = t;
}

int main()
{
	int x, y;
	printf("Enter the 1st number :");
	scanf("\n%d", &x);
	printf("\nEnter the 2nd number :");
	scanf("\n%d", &y);
        printf("\nbefore swap a: %d, b: %d", x, y);
	swap(&x, &y);
	printf("after swap a: %d,b: %d", x, y );
printf("\n");
	return 0;
}
