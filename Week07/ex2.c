#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* ptr;
	int n, i;

	printf("enter number of array elements :");
	scanf("%d",&n);

	ptr = (int*)malloc(n * sizeof(int));

	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {
		for (i = 0; i < n; ++i) {
			ptr[i] = i;
		}
		for (i = 0; i < n; ++i) {
			printf("ptr[%d]==%d\n",i, ptr[i]);
		}
	}
	return 0;
}

