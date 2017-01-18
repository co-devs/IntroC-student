#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	FILE *file;
	char *buffer;
	unsigned long fileLen;

	// open file test.txt
	FILE *fp = fopen("output/test.txt", "w+");
	//write to file
	fprintf(fp, "This is text...\n");
	// close file when done
	int fclose( FILE *fp );

	// Open file
	file = fopen("output/test.txt", "r");
	// If error!
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", "output/test.txt");
		return;
	}

	// Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	// Allocate memory
	buffer=(char *)malloc(fileLen+1);
	// If error!
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
		fclose(file);
		return;
	}

	// Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

	// Print buffer to screen
	printf(buffer);

	// free buffer
	free(buffer);
}
