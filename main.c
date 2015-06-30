#include <stdio.h>

#include "huffman.h"
#include <assert.h>

int main()
{
    int i;
    FILE *fp;
    int c;
    int freq[ALPHABET_SIZE] = {0};

    fp = fopen("test.txt", "r");

    // read in data and collect frequencies
    while ((c = fgetc(fp)) != EOF)
    {
        /*
        printf("0x%x == %c == %d \n", c, c, c);
        if (c == 0xe2)
        {
            if (ferror(fp))
                puts("EROROROROOROROROOROROROOR");
            fflush(stdout);
        } 
        */
        freq[c]++;
    }

    fclose(fp);

    // make a queue
    // take by two from queue and make huffman coding tree
    // dump the tree to the target file
    // reset file pointer
    // code the file using huffman coding

    /*
    for (i = 0; i < 256; ++i)
        if (freq[i])
            printf("char no. %d which is %c has freq: %d \n", i, i, freq[i]);
    */

    // prepare buffered reader and buffered writer
    BitStream *writer = init_write_stream("compressed_test.txt");
    BitStream *reader = init_read_stream("test.txt");

    prepare_huffman_code(freq);
    write_result_tree();
    huffman_encode_file(reader, writer);

    close_stream(writer);
    close_stream(reader);
}
