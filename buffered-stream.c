#include "buffered-stream.h"

#define READ 1
#define WRITE 2

BitStream *init_read_stream(char *file_name)
{
    BitStream *result = malloc(sizeof(BitStream));
    result->fp = fopen(file_name, "r");
    result->buffer = 0;
    result->buffer_pos = 0;
    result-> buff_type = READ;
    return result;
}

BitStream *init_write_stream(char *file_name)
{
    BitStream *result = malloc(sizeof(BitStream));
    result->fp = fopen(file_name, "w");
    result->buffer = 0;
    result->buffer_pos = 0;
    result->buff_type = WRITE;
    return result;
}

void buffered_write(int how_much, BitStream *file)
{

    while (how_much--)
    {

    }
}

void buffered_read(int how_much, BitStream *file);
