#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *ptr_buffer;
    FILE *ptr_file;
    unsigned long fileLen;
    int i = 0;

    /*
    Open a file, read the contents into buffer
     */
    if((ptr_file = fopen("test.txt", "r"))==NULL)
    {
        fprintf(stderr, "Unable to open the file for read\n");
        exit(1);
    }
    // Get file length
    fseek(ptr_file, 0, SEEK_END);
    fileLen=ftell(ptr_file);
    fseek(ptr_file, 0, SEEK_SET);

    // Allocate memory
    ptr_buffer=(char *)malloc(fileLen+1);
    // Error handling
    if (!ptr_buffer)
    {
        fprintf(stderr, "Memory error!");
        fclose(ptr_file);
        return;
    };
    // Read file contents into buffer
    if(fread(ptr_buffer, fileLen, 1, ptr_file) != 1)
    {
        fprintf(stderr, "Read error!\n");
        exit(1);
    }
    // fscanf(ptr_file, "%s", ptr_buffer);
    // Close file
    fclose(ptr_file);

    /*
    Encryption
     */
    for(i=0; i < fileLen; i++)
    {
        char rotated = (char)(ptr_buffer[i] + 1);
        // printf("%d : %02x : %c >> %02x : %c\n", i, ptr_buffer[i],  ptr_buffer[i], rotated, rotated);
        ptr_buffer[i] = rotated;
    }

    /*
    Write back to file
     */
    // Open file
    if((ptr_file = fopen("test.txt", "w+"))==NULL)
    {
        fprintf(stderr, "Unable to open the file for write\n");
        exit(1);
    };
    // Write to file
    // printf("%d\n", fprintf(ptr_file, ptr_buffer));
    fprintf(ptr_file, ptr_buffer);
    printf("File test.txt successfully encrypted ..!!");
    // printf("Wrote to file.\n");
    /*
    Close file, release buffer
     */
    // Close file
    fclose(ptr_file);
    // Print buffer to screen

    // fwrite(ptr_buffer, fileLen, 1, stdout);
    // printf("%s",ptr_buffer);
    // printf("%d\n",fileLen);

    // Free buffer
    free(ptr_buffer);
}
