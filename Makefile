CC = gcc

all: yelp1

yelp1: main.o general.o DictionaryBasedOnBST.o List.o
	$(CC) main.o general.o DictionaryBasedOnBST.o List.o -o yelp1
main.o: main.c
	$(CC) -c main.c
general.o: general.c
	$(CC) -c general.c
DictionaryBasedOnBST.o: DictionaryBasedOnBST.c
	$(CC) -c DictionaryBasedOnBST.c
List.o: List.c
	$(CC) -c List.c