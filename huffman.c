#include <assert.h>
#include <stdio.h>
#include "huffman.h"
#include "stack.h"

/*
 * Encoding file
 * =============
 * 1) compute the tree
 * 2) traverse the tree to prepare mapping from char to Symbol
 * 3) write the tree representation to the file
 * 4) using char_to_symbol write encode
 */

/*
 * Decoding file
 * =============
 * 1) Read in the tree from the file
 * 2) Decode bit by bit ;) writing results to the file
 */


// jest błąd, pewnie źle trawersuje drzewo kodowania. plz solve

static Tree *huffman_coding_tree = NULL;
static Tree *char_to_symbol[ALPHABET_SIZE]; // mapping from char to symbol

void compute_visit(Tree *t)
{
    assert(t != NULL);
    if (t->l == NULL && t->r == NULL)
    {
        // i am a leaf = fill in symbol data and the reverse map
        t->symbol = get_stack_val();
        t->symbol_len = get_stack_len();
        char_to_symbol[t->val] = t;
    } else
    {
        // if not, just traverse the tree
        if (t->l != NULL)
        {
            push_to_stack(0);
            compute_visit(t->l);
            pop_from_stack();
        }
        if (t->r != NULL)
        {
            push_to_stack(1);
            compute_visit(t->r);
            pop_from_stack();
        }
    }
}

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
    // compute char_to_symbol_map
    compute_visit(huffman_coding_tree);
}

void write_visit(BitStream *writer, Tree *t)
{
    if (t->l == NULL && t->r == NULL) 
    {
        buffered_write(1, writer, 1);
        buffered_write(8, writer, t->val);
    } else
    {
        buffered_write(1, writer, 0);
        if (t->l != NULL)
            write_visit(writer, t->l);
        if (t->r != NULL)
            write_visit(writer, t->r);
    }
    // jesli jestem lisciem, to wypisz 1 oraz 8 bitowy padded kod obecnego chara
    // w przeciwnym wypadku wypisz 0
}

void write_tree_to_file(BitStream *writer)
{
    assert(huffman_coding_tree != NULL);
    write_visit(writer, huffman_coding_tree);
}

void huffman_encode_file(BitStream *reader, BitStream *writer)
{
    assert(huffman_coding_tree != NULL);
    write_tree_to_file(writer);
    int c;
    while ((c = fgetc(reader->fp)) != EOF)
    {
        printf("huff enc char read. 0x%x == %c == %d \n", c, c, c);
        fflush(stdout);
        int how_much = char_to_symbol[c]->symbol_len;
        int what = char_to_symbol[c]->symbol_len;
        buffered_write(how_much, writer, what);
    }
}


void rec(Tree *t, int h)
{
    // recursion used by human-format tree writer
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
