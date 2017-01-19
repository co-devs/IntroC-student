#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void strRev(char *str)
{
    if(strlen(str)<2)
    {
        printf("<2\n");
    }else
    {
        swa
        printf(">=2\n");
    }
}

int main(void)
{
    char str[256];

    printf("Input a string: ");
    scanf("%[^\n]%*c", str);
    strRev(str);
    return 0;
}
