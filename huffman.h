#include "queue.h"
#include "buffered-stream.h"

void prepare_huffman_code(int freq[ALPHABET_SIZE]);
void write_result_tree();

void huffman_encode_file(BitStream *reader, BitStream *writer);
void read_int_tree(BitStream *reader);
