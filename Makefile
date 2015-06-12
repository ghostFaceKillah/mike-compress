main: main.c data.h queue.o
	gcc -g -o runme main.c queue.o

queue.o: queue.h queue.c
	gcc -g -c queue.c

clean:
	rm *.o runme
