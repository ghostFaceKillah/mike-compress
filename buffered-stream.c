#include "buffered-stream.h"

BitStream *init_read_stream(char *file_name)
{
    BitStream *result = malloc(sizeof(BitStream));
    result->fp = fopen();
}


BitStream *init_write_stream(char *file_name);
void buffered_write(int how_much, BitStream *file);
void buffered_read(int how_much, BitStream *file);
