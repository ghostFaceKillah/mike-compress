main: main.c data.h queue.o
	gcc -o runme main.c queue.o

queue.o: queue.h queue.c
	gcc -c queue.c

clean:
	rm *.o runme
