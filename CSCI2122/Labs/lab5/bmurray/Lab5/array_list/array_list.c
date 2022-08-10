#include "array_list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

ArrayList* alist_initialize(int max, int data, char* name){
       ArrayList* list = malloc(sizeof *list);
       list->maxSize = max;
       list->size = 0;
       list->itemSize = data;
       list-> arr = malloc(sizeof(void*) * max);
       list->type = name;

       return list;
}

bool alist_add(ArrayList* list, void* element){

	if (list->size == list->maxSize){
		alist_resize(list);
	}

	list->arr[list->size] = malloc(sizeof(list->itemSize));
	memcpy(list->arr[list->size], element, list->itemSize);


	if (list->arr[list->size] != NULL){
		list->size++;
		return true;
	}


	else {
		return false;
	}
}

bool alist_add_at(ArrayList* list, int index, void* element){


	list->arr[index] = malloc(sizeof(list->itemSize));

	for (int i = index; i < list->size-1; i++){
		memcpy(list->arr[i+1], list->arr[i], list->itemSize);
	}
	memcpy(list->arr[index], element, list->itemSize);

	if (list->size == list->maxSize){
		alist_resize(list);
	}

	if (list->arr[index] != NULL){
		list->size++;
		return true;
	}
	
	else {
		return false;
	}
}
void alist_clear(ArrayList* list){
	 list->size = 0;
}

void* alist_get(ArrayList* list, int index){ 
	return list->arr[index];
}

int alist_index_of(ArrayList* list, void* element){
	for (int i = 0; i < list->size; i++) {
		if(list->arr[i] == element){
			return i;
		}
	}
	return -1;
}

void* alist_remove(ArrayList* list, int index) {
	if (0 < index < list->size){
		for(int i = index-1; i < list->size-1; i++){
            list->arr[i] = list->arr[i + 1];
        }
		list->size--;
		}
 }

bool alist_destroy(ArrayList* list){
	for (int i = 0; i < list->size; i++)
		if (list->arr[i]){
			free(list->arr[i]);
		}
		free(list->arr);
		free(list);
		return true;
}

bool alist_resize(ArrayList* list) {
	int new_capacity = list->maxSize*2;
	list->arr = realloc(list->arr, sizeof(void*) * new_capacity);
	list->maxSize = new_capacity;
	return true;
}



	




