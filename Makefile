GCC          =   gcc

TEST_NAME    =   hash_test

LIB_NAME     =   libhashdyn.so

SOURCE       =   ./llist/src/llist.c ./hash/src/hash.c

CFLAGS       =   -Wall -pedantic -g -pipe

OBJ          =   hash.o llist.o

INCLUDES     =   -I./hash/includes/ -I./llist/includes

$(TEST_NAME): $(LIB_NAME) hash_tests.o
	$(GCC) -o $(TEST_NAME) $(INCLUDES) hash_tests.o -L. -lhashdyn 

hash_tests.o: ./hash/tests/hash_tests.c
	$(GCC) -c $(CFLAGS) $(INCLUDES) -o hash_tests.o ./hash/tests/hash_tests.c

$(LIB_NAME): $(OBJ)
	$(GCC) -shared -fpic -o $(LIB_NAME) $(OBJ)

$(OBJ): $(SOURCE) 
	$(GCC) -c $(CFLAGS) $(INCLUDES) -fpic $(SOURCE)

clean: 
	rm *.o $(TEST_NAME) *.so