#include <stdio.h>
#include "huffman.h"

int main()
{
    BitStream *reader = init_read_stream("compressed_test.txt");
    BitStream *writer = init_write_stream("re-test.txt");
    huffman_decode_file(reader, writer);
}
