#include <stdio.h>

#include "huffman.h"
#include <assert.h>

int main()
{
    int i;
    FILE *fp;
    int c;
    int freq[ALPHABET_SIZE] = {0};

    // read in data and collect frequencies - to be moved deeper into code
    fp = fopen("test.txt", "r");
    while ((c = fgetc(fp)) != EOF)
        freq[c]++;
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
    #ifdef DEBUG
    write_result_tree();
    #endif
    huffman_encode_file(reader, writer);

    close_stream(writer);
    close_stream(reader);
}
