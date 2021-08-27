#include <stdio.h>
#include <string.h>
int main()
{
    char in[100];
    printf("Enter a String : ");
    scanf("%s", in);
    printf("The string in reverse is: ");
    int i = 0;
    for ( i = strlen(in); i >= 0; i--)
    {
        putchar(in[i]);
    }
    printf("\n");
    return 0;
}
