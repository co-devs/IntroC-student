#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int charCounter(char *str)
{
    int strLength = strlen(str);
    int i = 0;
    int vowCount = 0;
    int consCount = 0;
    for(i=0; i < strLength; i++)
    {
        if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u' || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U')
        {
            ++vowCount;
        }
        else if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
        {
            ++consCount;
        }
    }
    printf("Number of vowels: %d\n", vowCount);
    printf("Number of consonants: %d\n", consCount);
    return 0;
}


int main(void)
{
    char str[256];

    printf("Input a string: ");
    scanf("%[^\n]%*c", str);
    charCounter(str);
    return 0;
}
