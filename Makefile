CC=gcc
CFLAGS=-lcurses

all:
	$(CC) $(CFLAGS) ./cdvd.c -o cdvd
