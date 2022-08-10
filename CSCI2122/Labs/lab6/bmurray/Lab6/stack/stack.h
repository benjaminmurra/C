#include <stdbool.h>
#ifndef  __STACK_HEADER
#define  __STACK_HEADER

typedef struct _Node {
    void* data;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _Stack {
    int size;
    int itemSize;
    char* type;
    struct _Node *first;
    struct _Node *last;
} Stack;

bool stack_push(Stack*,  void*);
Stack* stack_initialize(int , char* );
void* stack_pop(Stack* );
void* stack_peek(Stack* ) ;
int stack_size(Stack* );
bool stack_contains(Stack* , void* );
bool stack_destroy(Stack* );
bool stack_add_at(Stack* , int , void* );
void* llist_remove(Stack* , int );

#endif