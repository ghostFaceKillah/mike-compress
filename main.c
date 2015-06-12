#include <stdio.h>

#include "huffman.h"

#include <assert.h>

// void test_queue()
// {
//     int i;
//     Tree *top;
//     int freq;
//     for (i = 0; i < ALPHABET_SIZE; ++i)
//     {
//         get_top(&top, &freq);
//         printf("guy no. %d in the queue is %c with freq %d \n", i+1, top->val,
//                 freq);
//     }
//     assert(no_of_elems() == 0);
// }

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

    prepare_huffman_code(freq);
    write_result_tree();

    fclose(fp);
}
