GCC          			=   gcc

TEST_NAME    			=   btree_test

STATIC_LIB_NAME		=		libbtree.a

DYN_LIB_NAME     	=   libbtreedyn.so

SOURCE       			=   ./src/btree.c ./src/btree_support.c 

CFLAGS       			=   -Wall -pedantic -g -pipe

OBJ          			=   btree_support.o btree.o

INCLUDES     			=   -I./includes/

$(TEST_NAME): $(DYN_LIB_NAME) $(STATIC_LIB_NAME) btree_tests.o
	$(GCC) -o $(TEST_NAME) $(INCLUDES) llist_tests.o -L. -lbtreedyn 

btree_tests.o: ./tests/btree_tests.c
	$(GCC) -c $(CFLAGS) $(INCLUDES) -o llist_tests.o ./tests/btree_tests.c

$(DYN_LIB_NAME): $(OBJ)
	$(GCC) -shared -fpic -o $(DYN_LIB_NAME) $(OBJ)

$(STATIC_LIB_NAME): $(OBJ)
	ar cr $(STATIC_LIB_NAME) $(OBJ)

$(OBJ): $(SOURCE) 
	$(GCC) -c $(CFLAGS) $(INCLUDES) -fpic $(SOURCE)

clean: 
	rm *.o $(TEST_NAME) *.so *.a