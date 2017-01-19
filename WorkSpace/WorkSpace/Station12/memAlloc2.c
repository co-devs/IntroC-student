#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr_buffer;
    FILE *ptr_file;
    unsigned long fileLen;

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
    FILE *fp = fopen("output/test.txt", "w+");
    // Write to file
    fprintf(fp, ptr_buffer);
    printf("Wrote to file.\n");
    // close file
    fclose(fp);

    /*
    Open a file, read the contents into buffer, close file,
    print buffer, free buffer
     */
    if((ptr_file = fopen("output/test.txt", "r"))==NULL)
    {
        fprintf(stderr, "Unable to open the file\n");
        exit(1);
    }else printf("Opened file for read.\n");
    // Get file length
    fseek(ptr_file, 0, SEEK_END);
    fileLen=ftell(ptr_file);
    fseek(ptr_file, 0, SEEK_SET);
    // fileLen=100;

    // Allocate memory
    ptr_buffer=(char *)malloc(fileLen+1);
    // Error handling
    if (!ptr_buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(ptr_file);
        return;
    }else printf("Memory allocated for reading: fileLen is %d\n", fileLen);
    // Read file contents into buffer
    if(fread(ptr_buffer, fileLen, 1, ptr_file) != 1)
    {
        fprintf(stderr, "Read error!\n");
        exit(1);
    }else printf("Read successful.\n");
    // fscanf(ptr_file, "%s", ptr_buffer);
    // Close file
    fclose(ptr_file);
    // Print buffer to screen

    // fwrite(ptr_buffer, fileLen, 1, stdout);
    printf("%s",ptr_buffer);
    printf("%d\n",fileLen);

    // Free buffer
    free(ptr_buffer);
}
