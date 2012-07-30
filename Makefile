GCC                 =   gcc

TEST_LLIST_NAME     =   hash_llist_test

TEST_BTREE_NAME     =   hash_btree_test

LLIST_LIB_NAME      =   libllisthashdyn.so

BTREE_LIB_NAME      =   libbtreehashdyn.so

ST_LLIST_LIB_NAME   =   libllisthash.a

ST_BTREE_LIB_NAME   =   libbtreehash.a

SOURCE              =   ./hash/src/hash.c ./hash/src/hash_support.c 

CFLAGS              =   -Wall -pedantic -g -pipe 

LLIST_HASH_OBJ      =   hash.o hash_support.o

BTREE_HASH_OBJ      =   hash.o hash_support.o

LLIST_OBJ           =   ./llist/llist.o ./llist/llist_support.o

BTREE_OBJ           =   ./btree/btree.o ./btree/btree_support.o

INCLUDES            =   -I./hash/includes/ -I./llist/includes/ -I./btree/includes/

#Rules for LLIST_HASH

$(TEST_LLIST_NAME): $(LLIST_LIB_NAME) $(ST_LLIST_LIB_NAME) hash_llist_tests.o
	$(GCC) -o $(TEST_LLIST_NAME) $(INCLUDES) hash_llist_tests.o -L. -lllisthashdyn 

hash_llist_tests.o: ./hash/tests/hash_tests.c
	$(GCC) -c $(CFLAGS) $(INCLUDES) -DLIST_TYPE=1 -o hash_llist_tests.o ./hash/tests/hash_tests.c

$(LLIST_LIB_NAME): LLIST_HASH_OBJ $(LLIST_OBJ) 
	$(GCC) -shared -fpic -o $(LLIST_LIB_NAME) $(LLIST_HASH_OBJ) $(LLIST_OBJ)

$(ST_LLIST_LIB_NAME): LLIST_HASH_OBJ $(LLIST_OBJ)
	ar cr $(ST_LLIST_LIB_NAME) $(LLIST_HASH_OBJ) $(LLIST_OBJ)

LLIST_HASH_OBJ: $(SOURCE) 
	$(GCC) -c $(CFLAGS) $(INCLUDES) -DLIST_TYPE=1 -fpic $(SOURCE)

$(LLIST_OBJ):  
	make -C ./llist llist.o llist_support.o

$(TEST_BTREE_NAME): $(BTREE_LIB_NAME) $(ST_BTREE_LIB_NAME) hash_btree_tests.o
	$(GCC) -o $(TEST_BTREE_NAME) $(INCLUDES) hash_btree_tests.o -L. -lbtreehashdyn

hash_btree_tests.o: ./hash/tests/hash_tests.c
	$(GCC) -c $(CFLAGS) $(INCLUDES) -DLIST_TYPE=2 -o hash_btree_tests.o ./hash/tests/hash_tests.c

$(BTREE_LIB_NAME): $(BTREE_HASH_OBJ) $(BTREE_OBJ) 
	$(GCC) -shared -fpic -o $(BTREE_LIB_NAME) $(BTREE_HASH_OBJ) $(BTREE_OBJ)

$(ST_BTREE_LIB_NAME): $(BTREE_HASH_OBJ) $(BTREE_OBJ)
	ar cr $(ST_BTREE_LIB_NAME) $(BTREE_HASH_OBJ) $(BTREE_OBJ)

$(BTREE_HASH_OBJ): $(SOURCE) 
	$(GCC) -c $(CFLAGS) $(INCLUDES) -DLIST_TYPE=2 -fpic $(SOURCE)

$(BTREE_OBJ):  
	make -C ./btree btree.o btree_support.o

clean: 
	rm *.o ./btree/*.o ./llist/*.o $(TEST_LLIST_NAME) $(TEST_BTREE_NAME) *.so *.a