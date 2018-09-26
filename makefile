#Flags
CC = gcc
CFLAGS = -Wall -std=c11

#rules
main: 
	$(CC) $(CFLAGS) StructListDemo.c LinkedListAPI.c -o main -g
	
test: testAPI.c
	$(CC) $(CFLAGS) testAPI.c LinkedListAPI.c -o test -g
