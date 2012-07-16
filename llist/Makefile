PROGRAM_NAME = llist_test
CFLAGS       = -Wall -pedantic -g -pipe
OBJ          = llist.o main.o

$(PROGRAM_NAME): libllist.a
	gcc -L. -lllist -o $(PROGRAM_NAME)

libllist.a: llist.o main.o
	ar cr libllist.a main.o llist.o

llist.o: ./src/llist.c 
	gcc $(CFLAGS) -c ./src/llist.c -o llist.o

main.o: ./test/main.c 
	gcc $(CFLAGS) -c ./test/main.c -o main.o