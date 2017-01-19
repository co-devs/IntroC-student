#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr_buffer;
    FILE *ptr_file;
    unsigned long fileLen;
    float f;
    char str [80];

    /*Memory Allocation: Create Buffer to write text into file*/
    ptr_buffer = (char *)malloc(17 * sizeof(char));
    // error handling
    if(!ptr_buffer)
    {
        fprintf(stderr, "Memory allocation error!\n");
        exit(1);
    }else printf("Memory allocated for writing.\n");

    /*Generate text to write to file*/
    ptr_buffer = "ThisIsText...\n";
    // printf(ptr_buffer);

    /*Open file output/test.txt, write to it, and close the file*/
    // Open file
    FILE *fp = fopen("output//test.txt", "w+");
    // Write to file
    fprintf(fp, ptr_buffer);
    // close file
    fclose( fp );

    /*
    ---------------------------------------------------------
    Open a file, read the contents into buffer, close file,
    print buffer, free buffer
     */
    if((ptr_file = fopen("output//test.txt", "r"))==NULL)
    {
        fprintf(stderr, "Unable to open the file\n");
        exit(1);
    }else printf("Opened file for read.\n");
    fileLen=100;
    fscanf(ptr_file, "%f", &f);
    fscanf(ptr_file, "%s", str);
    fclose(ptr_file);
    printf("I have read: %f and %s \n", f, str);
}
