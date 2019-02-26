CC=gcc -std=c99

regex: main.c list.o regex.o
	$(CC) -o $@ $^

list.o: list.c list.h
	$(CC) -c list.c

regex.o: regex.c regex.h
	$(CC) -c regex.c

clean:
	rm list.o
	rm regex.o
	rm regex
