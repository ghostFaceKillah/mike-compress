#define ALPHABET_SIZE 256

typedef struct Tree
{
    unsigned char val;        // letter encoded by this node
    int symbol;      // series of 1s and 0s, binary code 
    int symbol_len;  // helps decode the above value
    struct Tree *l;
    struct Tree *r;
} Tree;

typedef struct
{
    int freq;
    Tree *tree;
} Data;
