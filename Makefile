main: main.c data.h queue.o huffman.o
	gcc -g -o runme main.c queue.o huffman.o

queue.o: queue.h queue.c
	gcc -g -c queue.c

huffman.o: huffman.h huffman.c
	gcc -g -c huffman.c

clean:
	rm *.o runme
