CFLAGS=-Wall -g

clean:
	rm -f c.exe

build:
	gcc $CFLAGS c.c
