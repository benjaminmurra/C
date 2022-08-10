COMPILER = gcc

CSTD = --std=c18

all : sorting sorting.o heap.o array_list.o
 
sorting: array_list.o sorting.o heap.o ../CI/objects/sorting/sortingM.o
	$(COMPILER) $(CSTD) array_list.o heap.o  sorting.o ../CI/objects/sorting/sortingM.o -o sorting

sorting.o : sorting.c 
	$(COMPILER) $(CSTD) -Ilib -c sorting.c -o sorting.o

heap.o : lib/heap.c lib/heap.h
	$(COMPILER) $(CSTD) -Ilib -c lib/heap.c -o heap.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/array_list.c -o array_list.o



clean :
	rm -f 
	rm -f heap
	rm -f array_list.o
	rm -f heap.o

	