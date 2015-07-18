#include <stdio.h>
#include "huffman.h"

int main()
{
    /*
     * Status of debugging work so far is that everything up to
     * decoding the tree from result is more-or-less working.
     * Possible places of errors:
     *   *) maybe no writes in the compressed file after the tree?
     *   *) maybe no reads from the compressed file after the tree?
     *
     * The best would be to manually search this guy.
     */
    BitStream *reader = init_read_stream("compressed_test.txt");
    BitStream *writer = init_write_stream("re-test.txt");
    huffman_decode_file(reader, writer);
    close_stream(reader);
    close_stream(writer);
}
