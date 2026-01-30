CC=gcc
CFLAGS=-O2 -Wall -std=c99

SRC=src/fft.c src/ifft.c
OBJ=$(SRC:.c=.o)

all: libfft.a

libfft.a: $(OBJ)
	ar rcs $@ $^

test: all
	$(CC) $(CFLAGS) tests/test_fft.c libfft.a -o test_fft

clean:
	rm -f src/*.o libfft.a test_fft