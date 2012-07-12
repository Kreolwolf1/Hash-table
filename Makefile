hashtable_main hashtable_test: llist.o
	gcc ./src/main.c llist.o -o hashtable_main
	gcc ./tests/test.c llist.o -o hashtable_test
llist.o: ./src/llist.c ./includes/llist.h
	gcc -c ./src/llist.c
clean:
	rm hashtable_main hashtable_test llist.o
