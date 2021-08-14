CC=gcc
CFLAGS=-lcurses

all:
	$(CC) $(CFLAGS) ./cbounce.c -o cbounce
