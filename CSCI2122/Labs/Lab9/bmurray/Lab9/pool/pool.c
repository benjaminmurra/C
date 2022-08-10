#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#include "pool.h"
#include "array_list.h"
#include "queue.h"
#include "linked_list.h"

void* compute(void* argument){
    if (argument == NULL) {
        return NULL;
    }
    Args* args = argument;
    int* result = malloc(sizeof(int));
    *result = arg->operation->op(arg->operation->a,arg->operation->b);
}

bool read_operations(char* file, Queue* q){

}

ArrayList* execute_thread_pool(char* file, int poolSize){

    Args args[poolSize];
    pthread_t threads[poolSize];

    ArrayList* alist = alist_initialize(10, 4, "int");
    Queue* queue = queue_initialize()

    for (int i = 0; i < poolSize ; i++){
        args[i]->iscomplete = false;
        pthread_create(&threads[i], NULL, compute, &args[i]);
    }
    while (queue_size(queue)>0){

    }
    for (int i = 0; i < poolSize; i++){
        pthread_join(threads[i], NULL);
    }

}

void print_sorted(ArrayList* alist){

}


int add(int a, int b){
	return (double) a + b;
}

int sub(int a, int b){
	return (int) a - b;
}

int mul(int a, int b){
	return (int) a * b;
}

