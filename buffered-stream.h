#include <stdio.h>

typedef struct
{
    FILE *fp;
    char buffer;
    int is_eof;
    int buffer_pos;
    int buff_type;
} BitStream;

BitStream *init_read_stream(char *file_name);
BitStream *init_write_stream(char *file_name);
void buffered_write(int how_much, BitStream *file_stream, int data);
unsigned int buffered_read(int how_much, BitStream *file_stream);
void close_stream(BitStream *stream);
