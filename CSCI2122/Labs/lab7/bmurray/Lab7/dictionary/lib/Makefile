COMPILER = gcc

CSTD = --std=c18


dictionary:linked_list.o stack.o queue.o dictionary.o bintree.o
	$(COMPILER) $(CSTD) linked_list.o stack.o queue.o search.o mains/dictM.o -o dictionary
 
dictionary.o : dictionary.c dictionary.h
	$(COMPILER) $(CSTD) -Ilib -c dictionary.c -o dictionary.o

stack.o : lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) -Ilib -c lib/stack.c -o stack.o

queue.o : lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) -Ilib -c lib/queue.c -o queue.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/linked_list.c -o linked_list.o

bintree.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) -Ilib -c bintree.c -o bintree.o


clean :
	rm -f dictionary.o
	rm -f queue.o
	rm -f stack.o
	rm -f queue.o
	
