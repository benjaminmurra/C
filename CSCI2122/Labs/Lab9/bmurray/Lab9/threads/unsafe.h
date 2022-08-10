#ifndef __UNSAFE_HEADER
#define __UNSAFE_HEADER

#include <stdbool.h>

typedef struct _Count {
    
    int counter;
}Count;

void* counting(void*);

void count_variable(int);

#endif