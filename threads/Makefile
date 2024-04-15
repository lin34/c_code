CC = clang
CFLAGS = -g -Wall

all: main argu safety

main: main.c
	$(CC) $(CFLAGS) -o $@ $^

argu: arguments.c
	$(CC) $(CFLAGS) -o $@ $^

safety: race_condition_sol.c
	$(CC) $(CFLAGS) -o $@ $^

debug: debugging.c
	$(CC) $(CFLAGS) -o $@ $^

volatile: volatile.c
	clang -O2 withthreads.c