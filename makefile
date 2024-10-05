CC = gcc
TARGETS = 1.c main.c 2.c

all: $(TARGETS)

1: 1.c
	$(CC) 1.c -o writer

2: 2.c
	$(CC) 2.c -o reader

main: main.c
	$(CC) main.c -o main

start:
	./main

