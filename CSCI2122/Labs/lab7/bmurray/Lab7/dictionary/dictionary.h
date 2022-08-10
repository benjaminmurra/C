#ifndef  __DICTIONARY_HEADER
#define  __DICTIONARY_HEADER

#include "bintree.h"
#include "queue.h"
#include "stack.h"
#include "dictionary.h"
#include "array_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct _Pair{
    void* first;
    void* second; 

} Pair;

typedef struct _Dictionary {
    BinaryTree* tree;
}Dictionary;


Dictionary* dict_initialize(int (*)(void*, void*), void (*)(void*));
bool dict_insert(Dictionary*, void*, void*);
void* dict_get(Dictionary*, void*);
ArrayList* dict_key_list(Dictionary*, int);
bool dict_contains(Dictionary*, void*);
#endif
