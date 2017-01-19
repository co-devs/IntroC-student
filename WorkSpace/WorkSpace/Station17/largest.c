#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findBiggest(int *intArr, int arrLen)
{
    int j=0;
    int largest = intArr[0];
    for(j=0; j<arrLen; j++)
    {
        if(intArr[j] > largest)
        {
            largest = intArr[j];
        }
    }
    return largest;
}

int main(void)
{
    int arrLen, i;
    int intArr[256];

    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &arrLen);
    printf ("Enter %d elements in the array:\n", arrLen);
    for(i=0; i<arrLen; i++)
    {
        printf("    element - %d : ", i);
        scanf("%d", &intArr[i]);
    }
    printf("The largest element in the array is :\n%d\n", findBiggest(intArr, arrLen));
    return 0;
}
