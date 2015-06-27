main: main.c data.h queue.o huffman.o
	gcc -g -o runme main.c queue.o huffman.o

test-buffered-stream: test-buffered-stream.c buffered-stream.o buffered-stream.h
	gcc -g test-buffered-stream.c buffered-stream.o -o test-buffered-stream

buffered-stream.o: buffered-stream.c buffered-stream.h
	gcc -g -c buffered-stream.c

queue.o: queue.h queue.c
	gcc -g -c queue.c

huffman.o: huffman.h huffman.c
	gcc -g -c huffman.c

clean:
	rm *.o runme test-buffered-stream heheXD.txt
