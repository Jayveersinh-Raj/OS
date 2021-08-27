#include <stdio.h>
#include <string.h>
int main()
{
    char input[100];
    printf("Enter a String : ");
    scanf("%s", input);
    printf("The string in reverse is: ");
    int i = 0;
    for ( i = strlen(input); i >= 0; i--)
    {
        putchar(input[i]);
    }
    printf("\n");
    return 0;
}