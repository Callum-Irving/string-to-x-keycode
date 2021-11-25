CFLAGS?=-Os -pedantic -Wall

all:
	$(CC) $(CFLAGS) -I$(PREFIX)/include main.c -L$(PREFIX)/lib -lX11 -o stringtoxkeycode

clean:
	rm -f stringtoxkeycode

