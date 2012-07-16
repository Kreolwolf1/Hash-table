GCC						=		gcc

TEST_NAME			=		llist_test

LIB_NAME			=		llist.a

CFLAGS       	=		-Wall -pedantic -g -pipe

OBJ          	= 	llist.o main.o

$(TEST_NAME): libllist.a
	gcc -L. -lllist -o $(TEST_NAME)

libllist.a: $(OBJ)
	ar cr libllist.a $(OBJ)

llist.o: ./src/llist.c 
	gcc $(CFLAGS) -c ./src/llist.c -o llist.o

main.o: ./test/main.c 
	gcc $(CFLAGS) -c ./test/main.c -o main.o
