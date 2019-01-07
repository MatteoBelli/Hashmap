CC=clang
CFLAGS=-O2 -Wall -Werror -I.
BINARY_TESTS=run_tests.exe

all: run_tests.exe

run_tests.exe: tests.o hashmap.o
	$(CC) -o $(BINARY_TESTS) $^
	./$(BINARY_TESTS)

tests.o: tests.c aiv_unit_test.h
	$(CC) -c -o $@ $(CFLAGS) $<

hashmap.o: hashmap.c hashmap.h
	$(CC) -c -o $@ $(CFLAGS) $<