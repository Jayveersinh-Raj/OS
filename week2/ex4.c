#include <stdio.h>

void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int main()
{
	int x, y;
	printf("Enter a 1st number :");
	scanf("\n%d", &x);
	printf("\nEnter a 2nd number :");
	scanf("\n%d", &y);
        printf("\nbefore swap | a -> %d, b-> %d", x, y);
	swap(&x, &y);
	printf("after swap | a-> %d,b-> %d", x, y );
printf("\n");
	return 0;
}
