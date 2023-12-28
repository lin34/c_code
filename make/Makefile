#https://www.youtube.com/watch?v=U161zVjv1rs&list=PL9IEJIKnBJjEPxenuhKU7J5smY4XjFnyg&index=3

CC = clang
CFLAGS = -G -Wall

all: myapp

list.o: list.h list.clang
	$(CC) $(CFLAGS) -c list.c

tree.o: tree.h tree.c
	$(CC) $(CFLAGS) -c tree.c

myapp: list.o tree.o main.c
	$(CC) $(CFLAGS) -o myapp main.c list.o tree.o

#variables in a make file to trim down target name, etc. automatic variables
#target name: $@
#Dependency list $^
#automatic variables %.o
CC = clang
CFLAGS = -G -Wall

all: myapp

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $^

myapp: list.o tree.o main.c
	$(CC) $(CFLAGS) -o $@ $^

#gcc -O2 test.c #optimization levels, O2

