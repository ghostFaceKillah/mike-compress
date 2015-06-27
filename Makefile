main: main.c data.h queue.o huffman.o buffered-stream.o
	gcc -g -o runme main.c queue.o huffman.o stack.o buffered-stream.o

test-buffered-stream: test-buffered-stream.c buffered-stream.o
	gcc -g test-buffered-stream.c buffered-stream.o -o test-buffered-stream

buffered-stream.o: buffered-stream.c buffered-stream.h
	gcc -g -c buffered-stream.c

stack.o: stack.c stack.h
	gcc -g -c stack.c

queue.o: queue.h queue.c
	gcc -g -c queue.c

huffman.o: huffman.h huffman.c stack.o queue.o
	gcc -g -c huffman.c

clean:
	rm *.o runme test-buffered-stream heheXD.txt
