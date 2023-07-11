CC = gcc
CFLAGS = -Wall -Wextra -lrt

all: attack victim

attack: attack.o
	$(CC) -o attack attack.o $(CFLAGS)

victim: victim.o
	$(CC) -o victim victim.o $(CFLAGS)

attack.o: attack.c
	$(CC) -c attack.c $(CFLAGS)

victim.o: victim.c
	$(CC) -c victim.c $(CFLAGS)

clean:
	rm -f *.o attack victim
