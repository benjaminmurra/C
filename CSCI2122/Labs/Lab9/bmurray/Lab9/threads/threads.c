#include <pthread.h>
#include <stdio.h>
#include "threads.h"
#include <stdlib.h>
#include <semaphore.h>

#define maxSize 10000000

void* fill(void* argument){
    Args* args = argument;

    int* arr = args->arr;
    int start = args->start;
    int end = args->end;

    for (int i = start; i < end; i++){
        arr[i]= arr[i]*arr[i];
    }
    return NULL;
}

void fill_memory(int* arr, int n){

    int range = maxSize / n;
    pthread_t threads[n];

    // Creating n threads
    for (int i = 0; i < n ; i++){
        Args* arg = malloc(sizeof(Args));
        arg->arr = arr;
        arg->start = i * range;
        arg->end = (i+1) * range;
        if (i == n - 1) {
            arg->end = maxSize;
        }
        pthread_create(&threads[i], NULL, fill, arg);
    }
    // joining n threads 
    for (int i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
    }
}