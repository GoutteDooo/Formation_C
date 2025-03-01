CC = gcc
CFLAGS = -Wall -Wextra
LDLIBS = -lcs50

addresses: addresses.c
	$(CC) $(CFLAGS) addresses.c $(LDLIBS) -o addresses
