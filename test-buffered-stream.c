#include "buffered-stream.h"

int main()
{
    BitStream *writer = init_write_stream("heheXD.txt");
    buffered_write(2, writer, 2); // 0b10
    buffered_write(2, writer, 3); // 0b11, together its 0b1011 == 0xB

    buffered_write(3, writer, 5);
    buffered_write(3, writer, 5);
    buffered_write(3, writer, 5);
    buffered_write(3, writer, 5);

    buffered_write(8, writer, 0xCE);

    buffered_write(1, writer, 1); // 0xF
    buffered_write(1, writer, 1);
    buffered_write(1, writer, 1);
    buffered_write(1, writer, 1);

    buffered_write(1, writer, 1); // 0xA
    buffered_write(1, writer, 0);
    buffered_write(1, writer, 1);
    buffered_write(1, writer, 0);

    buffered_write(4, writer, 0x0);

    buffered_write(4, writer, 0x1);
    buffered_write(4, writer, 0x2);
    buffered_write(4, writer, 0x3);
    buffered_write(4, writer, 0x4);

    buffered_write(4, writer, 0xd);

    close_stream(writer);
    BitStream *reader = init_read_stream("heheXD.txt");
    printf("read %x\n", buffered_read(4, reader)); // 0xB

    printf("read %d\n", buffered_read(3, reader)); // 5
    printf("read %d\n", buffered_read(3, reader)); // 5
    printf("read %d\n", buffered_read(3, reader)); // 5
    printf("read %d\n", buffered_read(3, reader)); // 5

    printf("read %x\n", buffered_read(4, reader)); // C

    printf("read %x\n", buffered_read(1, reader)); 
    printf("read %x\n", buffered_read(1, reader));
    printf("read %x\n", buffered_read(1, reader));
    printf("read %x\n", buffered_read(1, reader)); // E bit-by-bit

    printf("read %x\n", buffered_read(4, reader)); // F

    printf("read %x\n", buffered_read(4, reader)); // A
    printf("read %x\n", buffered_read(4, reader)); //0
    printf("read %x\n", buffered_read(4, reader)); // 1
    printf("read %x\n", buffered_read(4, reader)); // 2

    printf("read %x\n", buffered_read(4, reader)); // 3
    printf("read %x\n", buffered_read(8, reader)); // 4d 
    printf("read %x\n", buffered_read(4, reader)); // nico :(
    printf("read %x\n", buffered_read(4, reader)); // nico :(


    close_stream(reader);
}
