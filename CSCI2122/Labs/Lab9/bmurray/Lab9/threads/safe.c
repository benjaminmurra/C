#include <pthread.h>
#include <stdio.h>
#include "unsafe.h"
#include <stdlib.h>
#include <semaphore.h>

sem_t wait_here;

void* counting(void* argument){
    sem_wait (& wait_here);
    Count* count = argument;
    while (count->counter < 1000){
        count->counter++;
        printf("%d", count->counter);
        printf("\n");  
    }
    sem_post (&wait_here);
    return NULL;
}

void count_variable(int n){

    pthread_t threads[n];
    // Creating n threads
    Count* count = malloc(sizeof(Count));
    count->counter = 0;

    sem_init (&wait_here, 0, 1);

    for (int i = 0; i < n ; i++){
        pthread_create(&threads[i], NULL, counting, count);
    }
    
    // joining n threads 
    for (int i = 0; i < n; i++){
        pthread_join(threads[i], NULL);
    }
}