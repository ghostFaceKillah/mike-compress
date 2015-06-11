
#include <stdlib.h>
#include <stdio.h>

#include "queue.h"


static int how_much_in_q;
static Data data[ALPHABET_SIZE] = {0};

void fill_one_char_entry(Data *the_place, char c, int freq)
{
    the_place->freq = freq;
    the_place->tree = malloc(sizeof(Tree));
    the_place->tree->l = the_place->tree->r = NULL;
    the_place->tree->val = c;
}

void swap(int *a, int *b)
{
    (*a) = (*a)^(*b);
    (*b) = (*a)^(*b);
    (*a) = (*a)^(*b);
}

void swap_data_node(Data *a, Data *b)
{
    swap(&(a->freq), &(b->freq));
}


void heapify(i)
{
    int left = 2i;
    int right = 2i+1;
    int biggest = i;
    if ((left < how_much_in_q) && (data[left].freq > data[biggest].freq))
        biggest = left;
    if ((right < how_much_in_q) && (data[right].freq > data[biggest].freq))
        biggest = right;
    if (i != largest)
    {
        //swap(&(A[i]), &(A[largest]));
        //NOPE swap DATAZZZ
        // heapify(largest);
    }
}

void init_queue(int freq[ALPHABET_SIZE])
{
    int i;
    // copy the data in
    for (i = 0; i < ALPHABET_SIZE; ++i)
        fill_one_char_entry(&(data[i]), (char) i, freq[i]);
    how_much_in_q = ALPHABET_SIZE;
    // heapify
    for (i = ALPHABET_SIZE/2; i >= 0; --i)
        heapify(i);
}

void add_elem(Data *d)
{
    how_much_in_q++;
    printf("%d\n", how_much_in_q);
}
