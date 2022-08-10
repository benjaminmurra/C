COMPILER = gcc

CSTD = --std=c18


dictionary:linked_list.o stack.o queue.o dictionary.o bintree.o array_list.o
	$(COMPILER) $(CSTD) linked_list.o stack.o queue.o array_list.o bintree.o dictionary.o mains/dictM.o -o dictionary
 
dictionary.o : dictionary.c dictionary.h
	$(COMPILER) $(CSTD) -Ilib -c dictionary.c -o dictionary.o

stack.o : lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) -Ilib -c lib/stack.c -o stack.o

queue.o : lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) -Ilib -c lib/queue.c -o queue.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/linked_list.c -o linked_list.o

bintree.o : lib/bintree.c lib/bintree.h
	$(COMPILER) $(CSTD) -Ilib -c lib/bintree.c -o bintree.o

array_list.o : lib/array_list.c lib/array_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/array_list.c -o array_list.o

clean :
	rm -f dictionary.o
	rm -f queue.o
	rm -f stack.o
	rm -f queue.o
	
