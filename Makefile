CC=gcc 
CFLAGS=-std=c99 -Wall

regex: main.c list.o regex.o
	$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

regex.o: regex.c regex.h
	$(CC) $(CFLAGS) -c regex.c

clean:
	rm list.o
	rm regex.o
	rm regex
