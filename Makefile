CFLAGS = -DDEBUG -g

main: main.c data.h queue.o huffman.o buffered-stream.o
	gcc $(CFLAGS) -o runme main.c queue.o huffman.o stack.o buffered-stream.o

test-buffered-stream: test-buffered-stream.c buffered-stream.o
	gcc $(CFLAGS) test-buffered-stream.c buffered-stream.o -o test-buffered-stream

test-decode: test-decode.c main.c data.h queue.o huffman.o buffered-stream.o
	gcc $(CFLAGS) -o test-decode test-decode.c queue.o huffman.o stack.o buffered-stream.o

buffered-stream.o: buffered-stream.c buffered-stream.h
	gcc $(CFLAGS) -c buffered-stream.c

stack.o: stack.c stack.h
	gcc $(CFLAGS) -c stack.c

queue.o: queue.h queue.c
	gcc $(CFLAGS) -c queue.c

huffman.o: huffman.h huffman.c stack.o queue.o
	gcc $(CFLAGS) -c huffman.c

clean:
	rm *.o runme test-buffered-stream heheXD.txt
