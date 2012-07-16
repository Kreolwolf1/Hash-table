GCC						=		gcc

TEST_NAME 		=		llist_test

LIB_NAME			=		llist.a

CFLAGS       	=		-Wall -pedantic -g -pipe

SOURCES				=		llist.c \
									llist_support.c

OBJ          	= 	$(SOURCES:.c=.o)

$(PROGRAM_NAME): libllist.a
	gcc -L. -lllist -o $(PROGRAM_NAME)

libllist.a: llist.o main.o
	ar cr libllist.a main.o llist.o

# BUILD STATIC LIB .a
all						:

# 2- Build main.c using llist.h
# 1- Link llist.a with main_test.o	
test					:

llist.o: ./src/llist.c 
	gcc $(CFLAGS) -c ./src/llist.c -o llist.o

main.o: ./test/main.c 
	gcc $(CFLAGS) -c ./test/main.c -o main.o
