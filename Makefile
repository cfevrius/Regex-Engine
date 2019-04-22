CC=gcc 
CFLAGS=-std=c99 -Wall

regex: main.c list.o regex.o
	@echo Linking $@...
	@$(CC) $(CFLAGS) -o $@ $^

list.o: list.c list.h
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c list.c

regex.o: regex.c regex.h
	@echo Linking $@...
	@$(CC) $(CFLAGS) -c regex.c

clean:
	@echo Cleaning
	@rm list.o
	@rm regex.o
	@rm regex
