#include "buffered-stream.h"

int main()
{
    BitStream *writer = init_write_stream("heheXD.txt");
    buffered_write(4, writer, 0xA);
    buffered_write(4, writer, 0xA);
    buffered_write(4, writer, 0xC);
    buffered_write(4, writer, 0x0);

    buffered_write(4, writer, 0x0);
    buffered_write(4, writer, 0x0);
    buffered_write(4, writer, 0x0);
    buffered_write(4, writer, 0x0);

    buffered_write(4, writer, 0xd);
    close_stream(writer);
}
