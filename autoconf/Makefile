CC = gcc

VERSION= 0.0.1
CLFAGS = -g -O2

all: test-bin

test-bin : test2.c addition.c
	$(CC) $(CFLAGS) -DVERSION=\"$(VERSION)\" test2.c addition.c -o test

clean:
	rm -rf test

dclean:
	rm -rf pi config.* Makefile
 
