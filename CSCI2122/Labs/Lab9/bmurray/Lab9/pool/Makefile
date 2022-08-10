COMPILER = gcc

CSTD = --std=c18

 
pool:  pool.o array_list.o linked_list.o queue.o mains/poolM.o
	$(COMPILER) $(CSTD) queue.o array_list.o linked_list.o pool.o mains/poolM.o -o pool -lpthread

pool.o : pool.c pool.h
	$(COMPILER) $(CSTD)  -Ilib -c pool.c -o pool.o -lpthread

queue.o : lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) -Ilib -c lib/queue.c -o queue.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/linked_list.c -o linked_list.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/array_list.c -o array_list.o