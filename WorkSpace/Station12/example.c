    #include <stdio.h>
    #include <stdlib.h>

    int main(void)
    {
        // https://www.codingunit.com/writing-memory-to-a-file-and-reading-memory-from-a-file-in-c
        int counter;
        double *ptr_d;
        FILE *ptr_fp;

        // /*Part Z
        // * My additions
        // */
        // double *ptr_m;
        // FILE *ptr_fm;
        // // open file
        // if((ptr_fm = fopen("output/test.txt", "w+")) == NULL)
        // {
        //     printf("Unable to open file!\n")
        //     exit(1);
        // }else printf("Opened file successfully for writing.\n");
        // // Allocate memory
        // ptr_m = (double *)malloc(1 + sizeof(ptr_fm));
        // if(!ptr_m)
        // {
        //     printf("Memory allocation error!\n");
        //     exit(1);
        // }else printf("Memory allocation successful.\n");



        /* Part A
        * After some variable declaration we start the program with a
        * memory allocation statement. A piece of memory is requested using
        * malloc with a size of 10 times the size of a double. A pointer ptr_d
        * issued to point to this piece of memory. The rest of part A does
        * some simple error handling.
        */
        ptr_d = (double *)malloc(10 * sizeof(double));
        if(!ptr_d)
        {
            printf("Memory allocation error!\n");
            exit(1);
        }else printf("Memory allocation successful.\n");

        /* Part B
        * Part B is used to generate some random numbers (using rand function)
        * that are placed into our allocated piece of memory. We request for 10
        * random numbers. The rest of part B does some simple error handling.
        */
        for(counter = 0; counter < 10; counter++)
            ptr_d[counter] = (double) rand();

        /* Part C
        * Part C creates an empty file for writing. If a file with the same
        * name already exists its content is erased and the file is treated as
        * a new empty file. In order to open a file as a binary file (instead
        * of text), a “b” character has to be included in the mode string. The
        * rest of part C does some simple error handling.
        */
        if((ptr_fp = fopen("test.txt", "w+")) == NULL)
        {
            printf("Unable to open file!\n");
            exit(1);
        }else printf("Opened file successfully for writing.\n");

        /* Part D
        * In part D the content of the array is written to the file that was
        * opened in part C. After the array content has been written to the
        * file, the file is closed (fclose function) and the allocated memory
        * is released (free function.) The rest of part D does some simple
        * error handling.
        */
        if( fwrite(ptr_d, 10*sizeof(double), 1, ptr_fp) != 1)
        {
            printf("Write error!\n");
            exit(1);
        }else printf("Write was successful.\n");
        fclose(ptr_fp);
        free(ptr_d);

        /* Part E
        * again a piece of memory is allocated. This piece of memory is used to
        * write the memory to after we have read it from the file in the next
        * part. The rest is some simple error handling
        */
        ptr_d = (double *)malloc(10 * sizeof(double));
        if(!ptr_d)
        {
            printf("Memory allocation error!\n");
            exit(1);
        }else printf("Memory allocation successful.\n");

        /* Part F
        * the same as part C, but instead of opening the file for writing the
        * file is opened for reading by using “rb” in the mode string. The rest
        * is some simple error handling
        */
        if((ptr_fp = fopen("test.txt", "rb"))==NULL)
        {
            printf("Unable to open the file!\n");
            exit(1);
        }else printf("Opened file successfully for reading.\n");

        /* Part G
        * Almost the same as writing the entire array to the file, but instead
        * we use the fread function to read the content of the file. After the
        * read the file is closed using the function fclose. The rest is some
        * simple error handling. We now have written memory content to a file
        * and read the content of the file back into another piece of memory.
        * So we could have stopped here, but it’s always nice to visualize
        * things and that is where the last part is for.
        */
        if(fread(ptr_d, 10 * sizeof( double ), 1, ptr_fp) != 1)
        {
            printf( "Read error!\n" );
            exit( 1 );
        }else printf( "Read was successful.\n" );
        fclose(ptr_fp);

        /* Part H
        *  again we make a loop. This loop is used to print each member of the
        *  array onto the screen, nothing special.
        */
        printf("The numbers read from file are:\n");
        for(counter = 0; counter < 10; counter++)
            printf("%f ", ptr_d[counter]);

        /* Part I
        * As a last act we free the memory that we asked for in part E, so we
        * don’t create any memory leaks. That’s all for this tutorial. We hope
        * that you can see the uses of the example written above and use it in
        * your own program. The only thing I would change is to make a function
        * for memory allocation and open/read/write function, but I leave that
        * up to you.
        */
        free(ptr_d);
        return 0;
    }
