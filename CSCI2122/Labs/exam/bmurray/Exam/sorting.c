#include "array_list.h"
#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int compare (void*, void*);
void print(void* );
void readPeople(Heap*, char*);
void sortPeople();

typedef struct _Person
{
    char* name;	
	int age;	
} Person;

int compare (void* A, void* B){
    Person* x = A;
    Person* y = B;
    int result = strcmp(y->name, x->name);
    if ( result != 0) {
        result = -1;
    }  
    return result;
}

void print(void* a){
    Person* A = a;
    printf("%d ", A->name);

}
void readPeople(Heap* heap, char* file){

}
void sortPeople(){

}