COMPILER = gcc

CSTD = --std=c18

all : heap rheap
 
heap: array_list.o heap.o mains/heapM.o
	$(COMPILER) $(CSTD) array_list.o heap.o mains/heapM.o -o heap

rheap :  array_list.o  heap.o mains/rheapM.o
	$(COMPILER) $(CSTD) array_list.o heap.o mains/rheapM.o -o rheap

heap.o : heap.c heap.h
	$(COMPILER) $(CSTD) -Ilib -c heap.c -o heap.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/array_list.c -o array_list.o



clean :
	rm -f 
	rm -f heap
	rm -f array_list.o
	rm -f heap.o

	