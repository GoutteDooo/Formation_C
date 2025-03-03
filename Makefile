CC = gcc
CFLAGS = -Wall -Wextra -lcs50

addresses: addresses.c
	$(CC) $(CFLAGS) addresses.c -o addresses