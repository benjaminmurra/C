#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>
// A structure to represent a stack

 
// function to create a stack of given capacity. It initializes size of
// stack as 0
Stack* stack_initialize(int dataSize, char* dataName) {
  Stack* s =  malloc(sizeof(Stack));
  s->first = NULL;
  s->last = NULL;
  s->itemSize = dataSize;
  s->type = malloc(strlen(dataName));
  strcpy(s->type, dataName);
  s->size = 0;
  return s;
}
 

// Function to add an item to stack.  It increases top by 1
bool stack_push(Stack *s,  void *element) {

    return stack_add_at(s, 0, element);	
}


void* stack_pop(Stack* s){

    return llist_remove(s, 0);

}


void* stack_peek(Stack* s) {
  if (s->size > 0) {
        
        return s->first->data;
    }

}

int stack_size(Stack* s){
  return s->size;
}

bool stack_contains(Stack* s, void* element){
    if(s == NULL || element == NULL){
		  return false;
    }

    Node *curr = s->first;
    while (curr != NULL) {
        if (memcmp(curr->data, element, s->itemSize)==0) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

bool stack_destroy(Stack* llist){
    {
	// If the list is null, we can't destroy it. Return false.
	if(llist == NULL)
		return false;
	
	// If there are nodes available in the list, free them.
	if(llist->size > 0)
	{
		// Create a temporary node for holding nodes.
		Node *current = llist->first;
		Node *next    = NULL;
		
		// Iterate through all of the nodes.
		for(int i=0; i < llist->size; i++)
		{
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

	// Free the necessary linked list fields.
	free(llist->type);

	// Free the linked list.
	free(llist);

	// We destroyed the list. Return true.
	return true;
}


}

bool stack_add_at(Stack* s, int index, void* element)
{
	// If the list or element are null, return false.
	if(s == NULL || element == NULL)
		return false;

	// If the index doesn't fit in the bounds of the
	// list, we can return false.
	if(index < 0 || index > s->size)
		return false;

	// Create a new node and populate its data.
	Node *node = malloc(sizeof(*node));
	node->data = malloc(s->itemSize);
	memcpy(node->data, element, s->itemSize);
	
	// If we haven't added any nodes yet, we need to 
	// ensure both the first and last are updated.
	if(s->size == 0)
	{
		s->first = node;
		s->last  = node;
		node->next = NULL;
		node->prev = NULL;
	}
	// If we are adding on the first of the list,
	// we only need to deal with the first pointer.
	else if(index == 0)
	{
		node->next = s->first;
		node->prev = NULL;
		s->first->prev = node;
		s->first = node;
	}
	// If we are adding on the end of the list,
	// we only need to deal with the last pointer.
	else if(index == s->size)
	{
		node->next = NULL;
		node->prev = s->last;
		s->last->next = node;
		s->last = node;
	}
	// If we get here, we are inserting somewhere
	// in the middle of the list.
	else
	{
		// Create a temporary traversal node.
		Node *temp = s->first;

		// Iterate until we get to the node to be removed.
		for(int i=0; i < index; i++)
			temp = temp->next;
		
		// Set the new node's previous to the current node's previous.
		node->prev = temp->prev;

		// Set the new node's next to the current node.
		node->next = temp;
		
		// Set the previous node to point to the new one.
		temp->prev->next = node;

		// Set the current node to point to the new one.
		temp->prev = node;
	}

	// Increase the size of the linked list by 1.
	s->size++;
}

void* llist_remove(Stack* llist, int index)
{
	// If the list is null, return null.
	if(llist == NULL)
		return NULL;

	// If the index is out of bounds, return null.
	if(index < 0 || index >= llist->size)
		return NULL;
	
	// Create a temporary node.
	Node *temp = llist->first;

	// Iterate until we get to the node to be removed.
	for(int i=0; i < index; i++)
		temp = temp->next;
	
	// Adjust the pointers of adjacent nodes and linked list:
	// 1) If the list only has one node, we simply set the 
	//    linked list's first and last pointers to NULL.
	// 2) If we are removing the first node, we only have to
	//    adjust the next node's pointers and update the
	//    linked list's first node pointer.
	// 3) If we are removing the last node, we only have to
	//    adjust the previous node's pointers and update the
	//    linked list's last node pointer.
	// 4) Otherwise we adjust the next and prev nodes to make
	//    sure they point to each other.
	if(llist->size == 1)
	{
		llist->first = NULL;
		llist->last  = NULL;
	}
	else if(index == 0)
	{
		llist->first = temp->next;		
		llist->first->prev = NULL;
	}
	else if(index == llist->size-1)
	{
		llist->last = temp->prev;
		llist->last->next = NULL;
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
	}
	
	// Reduce the size of the linked list by 1.
	llist->size--;

	// Save the data from the node.
	void* data = temp->data;

	// Free the node.
	free(temp);

	// Return the removed node. It is up to the owner to free it.
	return data;
}
