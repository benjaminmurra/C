COMPILER = gcc

CSTD = --std=c18

all : search bfs dfs
 
search: linked_list.o stack.o queue.o search.o
	$(COMPILER) $(CSTD) linked_list.o stack.o queue.o search.o mains/searchM.o -o search

bfs :  linked_list.o stack.o queue.o search.o mains/bfsM.o
	$(COMPILER) $(CSTD) linked_list.o stack.o queue.o search.o mains/bfsM.o -o bfs

dfs :  linked_list.o stack.o queue.o search.o mains/dfsM.o
	$(COMPILER) $(CSTD) linked_list.o stack.o queue.o search.o mains/dfsM.o -o dfs

search.o : bintree.c bintree.h
	$(COMPILER) $(CSTD) -Ilib -c bintree.c -o search.o

stack.o : lib/stack.c lib/stack.h
	$(COMPILER) $(CSTD) -Ilib -c lib/stack.c -o stack.o

queue.o : lib/queue.c lib/queue.h
	$(COMPILER) $(CSTD) -Ilib -c lib/queue.c -o queue.o

linked_list.o : lib/linked_list.c lib/linked_list.h
	$(COMPILER) $(CSTD) -Ilib -c lib/linked_list.c -o linked_list.o



clean :
	rm -f bintree.o
	rm -f bfs
	rm -f dfs
	rm -f queue.o
	rm -f stack.o
	rm -f queue.o
	
