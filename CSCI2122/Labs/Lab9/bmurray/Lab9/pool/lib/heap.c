#include "array_list.h"
#include "heap.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

Heap* heap_initialize(int dataSize, char* dataName, int (*comp)(void*, void*), void (*print)(void*)){
    Heap* heap = malloc(sizeof(Heap));
      if(heap == NULL){
        return NULL;
    }
    ArrayList* alist = alist_initialize(15, dataSize, dataName);
    heap->alist = alist;
    heap->compare = comp;
    heap->print = print;

    return heap;
}

bool _heapify_up(Heap* heap, int index){
    int par = parent(index);
    int* parVal = alist_get(heap->alist, par);
    int* indexVal =  alist_get(heap->alist, index);

    if (index > 0 && heap->compare(parVal, indexVal) < 0){
        void* temp = heap->alist->arr[par];
        heap->alist->arr[par] = heap->alist->arr[index];
        heap->alist->arr[index] = temp;
        par = parent(index);
        _heapify_up(heap, par);
    }
    return true;
}

bool heap_insert(Heap* heap, void* element){
    alist_add(heap->alist, element);
    return _heapify_up(heap, heap->alist->size-1);
}

void* heap_remove(Heap* heap){
    void* temp = alist_get(heap->alist, 0);
    heap->alist->arr[0] = heap->alist->arr[heap->alist->size-1];
    heap->alist->arr[heap->alist->size-1] = temp; 
    temp = alist_remove(heap->alist, heap->alist->size-1);
    _heapify(heap, 0);

    return temp; 
}
void* heap_peek(Heap* heap){
    return heap->alist->arr[0];

}
int heap_size(Heap* heap){
    return heap->alist->size;
}
bool heap_contains(Heap* heap, void* element){
    if (alist_index_of(heap->alist, element) == -1){
        return false;
    }
    else { 
        return true;
    }
}

bool _heapify(Heap* heap, int index){ 

    int left = left_child(index);
    int* leftVal= alist_get(heap->alist, left);
    int right = right_child(index);
    int* rightVal= alist_get(heap->alist, right);
    int top = index;
    int* topVal= alist_get(heap->alist, top);
    int* indexVal = alist_get(heap->alist, index);


    if (left < heap->alist->size &&  heap->compare(leftVal, topVal) > 0) {
        top = left;
        topVal= alist_get(heap->alist, left);
    }

    if (right < heap->alist->size && heap->compare(rightVal, topVal) > 0) {    
        top = right;
        topVal= alist_get(heap->alist, right);

    }

    if (top != index) {
        void* temp = heap->alist->arr[index];
        heap->alist->arr[index] = heap->alist->arr[top];
        heap->alist->arr[top] = temp;
        _heapify(heap, top);
    }
    return true;
}

int parent(int i) {
    return (i - 1) / 2;
}


int left_child(int i) {
    return 2*i + 1;
}


int right_child(int i) {
    return 2*(i+ 1);
}
