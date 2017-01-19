#include <stdio.h>
#include <string.h>

// http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *str, int strStart, int strEnd)
{
   int i;
   if (strStart == strEnd)
     printf("%s\n", str);
   else
   {
       for (i = strStart; i <= strEnd; i++)
       {
          swap((str+strStart), (str+i));
          permute(str, strStart+1, strEnd);
          swap((str+strStart), (str+i)); //backtrack
       }
   }
}

/* Driver program to test above functions */
int main()
{
    char str[256];
    printf ("Enter a sentence: ");
    scanf("%s", str);
    // printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(str));
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}
