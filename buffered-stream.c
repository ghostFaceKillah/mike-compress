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
    printf("init write stream in"); fflush(stdout);
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
        printf("closing stream, have to write\n");
        fflush(stdout);
        int space_in_buffer = 8 - file_stream->buffer_pos;
        file_stream->buffer <<= space_in_buffer;
        assert(file_stream->fp != NULL);
        // write out to file
        file_stream->buffer_pos = 0;
        int written_chars_no = fputc(file_stream->buffer, file_stream->fp);
        printf("written %d chars to file.\n", written_chars_no);
    }
    fclose(file_stream->fp);
    free(file_stream);
}

unsigned int prepare_bit_mask(int len)
{
    assert(len <=8*sizeof(char));
    return (1 << len) - 1;
}

void buffered_write(int how_much, BitStream *file_stream, int data)
{
    int length_of_int = 32;
    assert(how_much <= length_of_int);
    printf("into buffered write \n"); fflush(stdout);
    while (how_much)
    {
        fflush(stdout);
        // see how much from how_much still fits into the buffer
        int space_in_buffer = 8 - file_stream->buffer_pos;
        int len = MIN(space_in_buffer, how_much);
        printf("buffered write loop,\
                how much is %d,\
                space_in_buffer is %d,\
                len is %d \n", how_much, space_in_buffer, len);
        file_stream->buffer <<= len;
        file_stream->buffer += (prepare_bit_mask(len) & data);
        how_much -= len;
        file_stream->buffer_pos += len;
        if (file_stream->buffer_pos == 8)
        {
            printf("trying to write\n");
            fflush(stdout);
            assert(file_stream->fp != NULL);
            // write out to file
            file_stream->buffer_pos = 0;
            int written_chars_no = fputc(file_stream->buffer, file_stream->fp);
            printf("written %d chars to file.\n", written_chars_no);
        }
        // shift buffer left
        // prepare
    }
    printf("out of buffered write \n \n"); fflush(stdout);
    // file_stream;
    // write how_much bits from data to result->buffer until it is full
    // when it is full, write to file
}

int buffered_read(int how_much, BitStream *file)
{
}
