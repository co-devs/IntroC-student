#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strRev(char *str)
{
    int i = 0;
    int strLength = strlen(str);
    char revStr[strLength];
    // printf("%")
    for(i=0; i < strLength; i++)
    {
        revStr[i] = str[strLength - i - 1];
        // printf("%c :> %c\n", str[strLength - i - 1], revStr[i]);
    }
    printf("Reversed string is: %s\n", revStr);
    // return revStr;
}

int main(void)
{
    char str[256];

    printf("Input a string to reverse: ");
    scanf("%[^\n]%*c", str);
    strRev(str);
    return 0;
}
