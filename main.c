#include <stdio.h>

#include "queue.h"

void test_queue()
{
    int i;
    Tree *top;
    for (i = 0; i < ALPHABET_SIZE; ++i)
    {
        top = get_top();
        printf("guy no. %d in the queue is %c \n", i+1, top->val);
    }
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
    test_queue();

    fclose(fp);
}
