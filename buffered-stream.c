#include "buffered-stream.h"

#define READ 1 
#define WRITE 2

BitStream *init_read_stream(char *file_name)
{
    BitStream *result = malloc(sizeof(BitStream));
    result->fp = fopen(file_name, "r");
    result->buffer = 0;
    result->buff_type = READ;
    result->buffer_pos = 0;
    return result;
}

const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

BitStream *init_write_stream(char *file_name)
{
    BitStream *result = malloc(sizeof(BitStream));
    result->fp = fopen(file_name, "r");
    result->buffer = 0;
    result->buff_type = READ;
    result->buffer_pos = 0;
    return result;
}

unsigned int prepare_bit_mask(int from, int to)
{
    // from 1 to 23
    //
}

void buffered_write(int how_much, BitStream *file_stream, int data)
{
    // file_stream;
    // write how_much bits from data to result->buffer until it is full
    // when it is full, write to file
}

int buffered_read(int how_much, BitStream *file)
{
}
