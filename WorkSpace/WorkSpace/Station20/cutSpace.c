#include <stdio.h>
#include <ctype.h>

int main(void)
{
    FILE *pfile;
    int a;
    printf("Remove the spaces between two words  :\n-----------------------------------------\n");
    pfile = fopen("test.txt", "r");

    printf("The content of the file is:\nThe quick brown fox jumps over the lazy dog\n");
    printf("After removing the spaces the content is :\n");
    if (pfile)
    {
        do
        {
            a = fgetc(pfile);
            if (isgraph(a)) putchar (a);
        } while (a != EOF);
    }
    printf("\n\n");
    return 0;
}
