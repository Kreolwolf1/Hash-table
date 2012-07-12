PROGRAM_NAME = llist_test
CFLAGS       = -Wall -pedantic -g -pipe
OBJ          = llist.o main.o

$(PROGRAM_NAME): $(OBJ)
	gcc $(C_FLAGS) $(OBJ) -o $(PROGRAM_NAME)

llist.o: ./src/llist.c 
	gcc $(CFLAGS) -c ./src/llist.c -o llist.o

main.o: ./test/main.c 
	gcc $(CFLAGS) -c ./test/main.c -o main.o