#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "buffered-stream.h"

#define READ 1 
#define WRITE 2
#define MIN(x,y) x > y ? y : x;

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
    result->fp = fopen(file_name, "w+");
    result->buffer = 0;
    result->buff_type = WRITE;
    result->buffer_pos = 0;
    return result;
}

void close_stream(BitStream *file_stream)
{
    if (file_stream->buff_type == WRITE)
    {
        int space_in_buffer = 8 - file_stream->buffer_pos;
        file_stream->buffer <<= space_in_buffer;
        assert(file_stream->fp != NULL);
        // write out to file
        file_stream->buffer_pos = 0;
        int written_chars_no = fputc(file_stream->buffer, file_stream->fp);
    }
    fclose(file_stream->fp);
    free(file_stream);
}

unsigned int prepare_bitmask(int len)
{
    assert(len <=8*sizeof(char));
    return (1 << len) - 1;
}

unsigned int prepare_front_bitmask(int len)
{
    return prepare_bitmask(8) - prepare_bitmask(8-len);
}

void buffered_write(int how_much, BitStream *file_stream, int data)
{
    // this is all wrong!!!!
    // just think what happens if we want to push a lot of data
    //  for example more than fits in the current buffer
    //  this needs to be fixed!
    int length_of_int = 32;
    assert(how_much <= length_of_int);
    while (how_much)
    {
        // see how much from how_much still fits into the buffer
        int space_in_buffer = 8 - file_stream->buffer_pos;
        int len = MIN(space_in_buffer, how_much);
        file_stream->buffer <<= len;
        int offset = how_much - len;
        file_stream->buffer += ((prepare_bitmask(len) << offset) & data) >> offset;
        how_much -= len;
        file_stream->buffer_pos += len;
        if (file_stream->buffer_pos == 8)
        {
            assert(file_stream->fp != NULL);
            // write out to file
            file_stream->buffer_pos = 0;
            int written_chars_no = fputc(file_stream->buffer, file_stream->fp);
        }
    }
    // file_stream;
    // write how_much bits from data to result->buffer until it is full
    // when it is full, write to file
}

unsigned int buffered_read(int how_much, BitStream *file_stream)
{
    assert(how_much <= 32);
    unsigned int result = 0;
    while(how_much)
    {
        if (file_stream->buffer_pos == 0)
        {
            // read in one char from file
            file_stream->buffer = (char) fgetc(file_stream->fp);
            file_stream->buffer_pos = 8;
        }
        int len = MIN(file_stream->buffer_pos, how_much);
        result <<= len;
        result += (prepare_front_bitmask(len) & file_stream->buffer) >> (8 - len);
        file_stream->buffer <<= len; // redundant, can be done faster, but for now it's ok
        file_stream->buffer_pos -= len;
        how_much -= len;
    }
    return result;
}
