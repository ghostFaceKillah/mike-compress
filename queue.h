#include "data.h"

#define ALPHABET_SIZE 256

void add_elem(int freq, Tree *tree);
void init_queue(int freq[ALPHABET_SIZE]);
Tree *get_top();
Tree *make_tree(char val, Tree *r, Tree *l);
