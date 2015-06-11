#include <stdio.h>

#include "queue.h"

void swap(int* a, int* b)
{
    (*a) = (*a)^(*b);
    (*b) = (*a)^(*b);
    (*a) = (*a)^(*b);
}

int main()
{
    int i;
    FILE *fp;
    char c;
    int freq[ALPHABET_SIZE] = {0};

    fp = fopen("test.txt", "r");

    // read in data and collect frequencies
    while ((c = fgetc(fp)) != EOF)
        freq[c]++;

    // make a queue
    // take by two from queue and make huffman coding tree
    // dump the tree to the target file
    // reset file pointer
    // code the file using huffman coding

    for (i = 0; i < 256; ++i)
        if (freq[i])
            printf("char no. %d which is %c has freq: %d \n", i, i, freq[i]);

    init_queue(freq);

    fclose(fp);
}
