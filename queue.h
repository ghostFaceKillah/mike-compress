#include "data.h"

void init_queue(int freq[ALPHABET_SIZE]);
void add_elem(int freq, Tree *tree);
void get_top(Tree **t, int *freq);
Tree *make_tree(char val, Tree *r, Tree *l);
int no_of_elems();
