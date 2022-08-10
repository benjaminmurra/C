#ifndef __SAFE_HEADER
#define __SAFE_HEADER

#include <stdbool.h>
#include "pool.h"
#include "array_list.h"
#include "queue.h"
#include "linked_list.h"

typedef struct _Operation {
    int (*op)(int, int);
    int a;
    int b;
}Operation;

typedef struct _Args {
    Operation* operation;
    bool iscomplete;
}Args;


void* compute(void*);
bool read_operations(char*, Queue*);
void count_variable(int);
ArrayList* execute_thread_pool(char*, int);
void print_sorted(ArrayList*);

int add(int, int);
int sub(int, int);
int mul(int, int);

#endif