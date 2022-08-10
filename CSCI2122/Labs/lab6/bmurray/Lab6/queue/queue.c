#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include <stdlib.h>
#include <string.h>

Queue* queue_initialize(int dataSize, char* dataName){
    Queue* q =  malloc(sizeof(Queue));

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    q->itemSize = dataSize;
    q->type = malloc(strlen(dataName));
    strcpy(q->type, dataName);

    return q;
}

bool queue_enqueue(Queue* q, void* element){
    if(q == NULL || element == NULL){
		return false;
    }

    Node *newNode = malloc(sizeof(Node));

    if(newNode == NULL) {
        return false;
    }

    newNode->data = malloc(q->itemSize);

    if(newNode->data == NULL){
        free(newNode);
        return false;
    }

    newNode->next = NULL;
    memcpy(newNode->data, element, q->itemSize);
    
    if(q->size == 0){
        q->front = q->rear = newNode;
    }
    else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    
    q->size++;
    return true;
}
	

void* queue_dequeue(Queue* q) { 
    if(q == NULL){
		return false;
    }
    // If queue is empty, return NULL. 
    if (q->front == NULL) {
        return NULL; 
    }
    // Store previous front and move front one node ahead 
    Node* temp = q->front; 
    q->front = q->front->next; 
  
    // If front becomes NULL, then change rear also as NULL 
    if (q->front == NULL) {
        q->rear = NULL; 
    }
    q->size--;
    return temp->data; 
} 

void* queue_peek(Queue* q){
    if (q->size > 0) {
        
        return q->front->data;
    }
}

int queue_size(Queue* q){
    return q->size;
}

bool queue_contains(Queue* q, void* element){
    if(q == NULL || element == NULL){
		return false;
    }

    Node *curr = q->front;
    while (curr != NULL) {
        if (memcmp(curr->data, element, q->itemSize)==0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool queue_destroy(Queue *q){
	// If the list is null, we can't destroy it. Return false.
	if(q == NULL)
		return false;
	
	// If there are nodes available in the list, free them.
	if(q->size > 0){
		// Create a temporary node for holding nodes.
		Node *current = q->front;
		Node *next    = NULL;
		
		// Iterate through all of the nodes.
		for(int i=0; i < q->size; i++){
			// Store a pointer to the next node.
			next = current->next;

			// Free this node's data.
			free(current->data);

			// Free this node.
			free(current);

			// We move to the next node.
			current = next;
		}
	}
    free(q->type);

	// Free the linked list.
	free(q);

	// We destroyed the list. Return true.
	return true;
}



