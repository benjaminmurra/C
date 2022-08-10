#include "bintree.h"
#include "queue.h"
#include "stack.h"
#include "dictionary.h"
#include "array_list.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


Dictionary* dict_initialize (int (*comp)(void*, void*), void (*printFun)(void*)){
    Dictionary* dict = malloc(sizeof(Dictionary));
    dict->tree = bintree_initialize(sizeof(struct _Pair), "Pair", comp, printFun);
    return dict;
}

bool dict_insert (Dictionary* dict, void* key, void* value){
    Pair* pair = malloc(sizeof(Pair));

    pair->first = key;
    pair->second = value;

    return bintree_insert_replace(dict->tree, pair);

}

void* dict_get(Dictionary* dict, void* key){

    BinaryTreeNode *tempNode = dict->tree->top;

    while (tempNode != NULL && dict->tree->compare(tempNode->data, key) != 0){
        if (dict->tree->compare(tempNode->data, key) < 0){
            tempNode = tempNode->left;
        }
        else { 
            tempNode = tempNode->right;  
        }
    }
    if (tempNode == NULL){
        return NULL;
    }
   return tempNode->data.second;
}





ArrayList* dict_key_list(Dictionary* dict, int size){

}

bool dict_contains(Dictionary* dict, void* key){

}


