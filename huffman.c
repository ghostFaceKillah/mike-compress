#include <stdio.h>

#include "huffman.h"

static Tree *huffman_coding_tree = NULL;

void prepare_huffman_code(int freq[ALPHABET_SIZE])
{
    init_queue(freq);
    Tree *t1, *t2;
    int f1, f2;
    while (no_of_elems() > 1)
    {
        get_top(&t1, &f1);
        get_top(&t2, &f2);
        if (f1 || f2)
            add_elem(f1+f2, make_tree(0, t1, t2));
    }
    get_top(&huffman_coding_tree, &f2);
}

// Symbol enconde(char c);
// char Decode(symbol c)

void rec(Tree *t, int h)
{
    int i;
    if (t->r != NULL)
        rec(t->r, h+1);
    // wypisz
    for (i = 0; i < h; ++i) 
        printf("\t");
    if (t->r == NULL && t->l == NULL)
        printf("leaf: %c\n", t->val);
    else
        printf("node\n");
    if (t->l != NULL)
        rec(t->l, h+1);

}

void write_result_tree()
{
    if (huffman_coding_tree == NULL)
        printf("Drzewo jest puste :(\n");
    else
        rec(huffman_coding_tree, 0);
}
