
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "queue.h"


static int last_elem_index = 1;
static Data data[ALPHABET_SIZE + 1] = {0};

void fill_one_char_entry(Data *the_place, char c, int freq)
{
    the_place->freq = freq;
    the_place->tree = malloc(sizeof(Tree));
    the_place->tree->l = the_place->tree->r = NULL;
    the_place->tree->val = c;
}

void swap_int(int *a, int *b)
{
    assert(a != b);
    (*a) = (*a)^(*b);
    (*b) = (*a)^(*b);
    (*a) = (*a)^(*b);
}

void swap(Data *a, Data *b)
{
    assert(a != b);
    swap_int(&(a->freq), &(b->freq));
    swap_int((int *) &(a->tree), (int *) &(b->tree));
    // int temp_freq = a->freq;
    // Tree *temp_tree = a->tree;
    // a->tree = b->tree;
    // a->freq = b->freq;
    // b->tree = temp_tree;
    // b->freq = temp_freq;
}

void heapify(int i)
{
    assert(i > 0);
    assert(data[i].tree != NULL);
    int left = 2*i;
    int right = 2*i + 1;
    int biggest = i;
    if ((left <= last_elem_index) && (data[left].freq < data[biggest].freq))
        biggest = left;
    if ((right <= last_elem_index) && (data[right].freq < data[biggest].freq))
        biggest = right;
    if (i != biggest)
    {
        assert(i != 0);
        assert(biggest != 0);
        swap(&(data[i]), &(data[biggest]));
        heapify(biggest);
    }
}


void init_queue(int freq[ALPHABET_SIZE])
{
    int i;
    // copy the data in
    for (i = 0; i < ALPHABET_SIZE; ++i)
        fill_one_char_entry(&(data[i+1]), (char) i, freq[i]);
    last_elem_index = ALPHABET_SIZE;
    // heapify
    for (i = last_elem_index/2; i > 0; --i)
        heapify(i);
}

int no_of_elems()
{
    return last_elem_index;
}

void add_elem(int freq, Tree *tree)
{
    last_elem_index++;
    // static Data data[ALPHABET_SIZE] = {0};
    data[last_elem_index].freq = freq;
    data[last_elem_index].tree = tree;
    int i;
    for (i = last_elem_index / 2; i > 0; i /= 2)
        heapify(i);
}

void get_top(Tree **t, int *freq)
{
    assert(last_elem_index >= 1);
    *t = data[1].tree;
    *freq = data[1].freq;
    if (last_elem_index > 1)
    {
        swap(&(data[1]), &(data[last_elem_index]));
        --last_elem_index;
        heapify(1);
    } else if (last_elem_index == 1)
        last_elem_index = 0;
}

Tree *make_tree(char val, Tree *r, Tree *l)
{
    Tree *to_return = malloc(sizeof(Tree));
    to_return->r = r;
    to_return->l = l;
    to_return->val = val;
    return to_return;
}
