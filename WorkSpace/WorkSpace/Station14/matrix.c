#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int testMatrix[3][3] ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int matrix[10][10];
    int i, j, m, n, sum = 0;
    int rowLength = sizeof(testMatrix[0]) / sizeof(int);
    int rowCount = sizeof(testMatrix) / sizeof(int) / rowLength;
    /*
    Get Matrix
     */
    printf("Enter Matrix Dimensions:\n");
    scanf("%d %d", &m, &n);
    printf("Enter matrix coefficients:\n");
    for(i=0; i < m; i++)
    {
        for(j=0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    /*
    Sum Rows
     */
    // printf("%d rows of %d ints each.\n", rowCount, rowLength);
    if(m > 0)
    {
        rowLength = n;
        rowCount = m;
    }else fprintf(stderr, "Error! Dimensions eq 0");
    for(i=0; i < rowCount; i++)
    {
        // printf("Row %d\n", i);
        for(j=0; j < rowLength; j++)
        {
            // printf("[%d,%d]\n", i, j);
            sum = sum + matrix[i][j];
        }
        printf("Sum of row %d = %d\n", i+1, sum);
        sum = 0;
    }
}
