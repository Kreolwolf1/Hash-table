GCC          			=   gcc

TEST_NAME    			=   llist_test

STATIC_LIB_NAME		=		libllist.a

DYN_LIB_NAME     	=   libllistdyn.so

SOURCE       			=   ./src/llist.c ./src/llist_support.c 

CFLAGS       			=   -Wall -pedantic -g -pipe

OBJ          			=   llist_support.o llist.o

INCLUDES     			=   -I./includes/

$(TEST_NAME): $(DYN_LIB_NAME) $(STATIC_LIB_NAME) llist_tests.o
	$(GCC) -o $(TEST_NAME) $(INCLUDES) llist_tests.o -L. -lllistdyn 

llist_tests.o: ./test/main.c
	$(GCC) -c $(CFLAGS) $(INCLUDES) -o llist_tests.o ./test/main.c

$(DYN_LIB_NAME): $(OBJ)
	$(GCC) -shared -fpic -o $(DYN_LIB_NAME) $(OBJ)

$(STATIC_LIB_NAME): $(OBJ)
	ar cr $(STATIC_LIB_NAME) $(OBJ)

$(OBJ): $(SOURCE) 
	$(GCC) -c $(CFLAGS) $(INCLUDES) -fpic $(SOURCE)

clean: 
	rm *.o $(TEST_NAME) *.so *.a