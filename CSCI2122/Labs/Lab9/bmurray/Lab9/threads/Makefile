COMPILER = gcc

CSTD = --std=c18

all: threads unsafe safe
 
threads:  threads.o mains/threadsM.o
	$(COMPILER) $(CSTD)   threads.o mains/threadsM.o  -o threads -lpthread

threads.o : threads.c threads.h
	$(COMPILER) $(CSTD)  -Ilib -c threads.c -o threads.o -lpthread

unsafe:  unsafe.o mains/unsafeM.o
	$(COMPILER) $(CSTD)   unsafe.o mains/unsafeM.o  -o unsafe -lpthread

unsafe.o : unsafe.c unsafe.h
	$(COMPILER) $(CSTD)  -Ilib -c unsafe.c -o unsafe.o -lpthread

safe:  safe.o mains/safeM.o
	$(COMPILER) $(CSTD)   safe.o mains/safeM.o  -o safe -lpthread

safe.o : safe.c safe.h
	$(COMPILER) $(CSTD)  -Ilib -c safe.c -o safe.o -lpthread

clean :
	