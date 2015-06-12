#define ALPHABET_SIZE 256

typedef struct Tree {
    char val;
    struct Tree *l;
    struct Tree *r;
} Tree;

typedef struct {
    int freq;
    Tree *tree;
} Data;
