#include <stdbool.h>
#ifndef  __QUEUE_HEADER
#define  __QUEUE_HEADER

typedef struct _Node {
    void* data;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct _Queue {
    int size;
    int itemSize;
    char* type;
    struct _Node *front;			
	struct _Node *rear;
} Queue;

Queue* queue_initialize(int , char* );
bool queue_enqueue(Queue* , void* );
void* queue_dequeue(Queue* );
void* queue_peek(Queue* );
int queue_size(Queue* );
bool queue_contains(Queue*, void* );
bool queue_destroy(Queue*);
int empty(Queue *);


#endif
