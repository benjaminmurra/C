#include <pthread.h>
#include <stdio.h>
#include "unsafe.h"
#include <stdlib.h>
#include <semaphore.h>

void* counting(void* argument){
    Count* count = argument;
    while (count->counter < 1000){
        count->counter++;
        printf("%d", count->counter);
        printf("\n");
    }
    return NULL;
}

void count_variable(int n){

    pthread_t threads[n];
    // Creating n threads
    Count* count = malloc(sizeof(Count));
    count->counter = 0;

    for (int i = 0; i < n ; i++){
        pthread_create(&threads[i], NULL, counting, count);
    }
    // joining n threads 
    for (int i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
    }
}