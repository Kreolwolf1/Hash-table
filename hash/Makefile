GCC           =   gcc

TEST_NAME     =   hash_test

LIB_NAME      =   libhashdyn.so

SOURCE        =   ../llist/src/llist.c ./src/hash.c

CFLAGS        =   -Wall -pedantic -g -pipe

OBJ           =   hash.o llist.o

$(TEST_NAME): $(LIB_NAME) hash_tests.o
	$(GCC) -o $(TEST_NAME) hash_tests.o -L. -lhashdyn 

hash_tests.o: ./tests/hash_tests.c
	$(GCC) -c $(CFLAGS) -o hash_tests.o ./tests/hash_tests.c

$(LIB_NAME): $(OBJ)
	$(GCC) -shared -fpic -o $(LIB_NAME) $(OBJ)

$(OBJ): $(SOURCE) 
	$(GCC) -c $(CFLAGS) -fpic $(SOURCE)

clean: 
	rm *.o $(TEST_NAME) *.so