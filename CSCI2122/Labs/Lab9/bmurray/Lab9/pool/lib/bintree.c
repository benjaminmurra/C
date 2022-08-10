#include "bintree.h"
#include "queue.h"
#include "stack.h"

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

BinaryTree* bintree_initialize(int typeSize, char* typeName, int (*comp)(void*, void*), void (*printFun)(void*)){

    BinaryTree* tree = malloc(sizeof(BinaryTree));

    if(tree == NULL){
        return NULL;
    }

    tree->top = NULL;
    tree->itemSize = typeSize;
    tree->type = malloc(strlen(typeName)+1);
    strcpy(tree->type, typeName);
    tree->compare = comp;
    tree->print = printFun;
 
    return tree;
}

BinaryTreeNode* bintree_create_node(int dataSize, void* element){
    BinaryTreeNode* node = malloc(sizeof(BinaryTreeNode));
    node->left = NULL;
    node->right = NULL;
    node->data = malloc(dataSize);
    memcpy(node->data, element, dataSize);

    return node;
}

bool bintree_insert(BinaryTree* tree, void* element){
    if(tree == NULL || element == NULL){
        return false;
    }

    if(tree->top == NULL) {
        tree->top = bintree_create_node(tree->itemSize, element);
        if(tree->top == NULL){
            return false;
        }
        return true;
    }
    else {
        return _bintree_insert_recursive(tree, tree->top, element);  
    }
}

bool bintree_search(BinaryTree* tree, void* element){
    if(tree == NULL || element == NULL)
        return false;
    return _bintree_search_recursive(tree, tree->top, element);
}
 
void bintree_print_in_order(BinaryTree* tree){
    if(tree == NULL || tree->top == NULL)
        return;

    _bintree_in_order_recursive(tree, tree->top);
}
 
void bintree_print_pre_order(BinaryTree* tree){
    if(tree == NULL || tree->top == NULL)
        return;
 
    _bintree_pre_order_recursive(tree, tree->top);
}
 
void bintree_print_post_order(BinaryTree* tree){
    if(tree == NULL || tree->top == NULL)
        return;
 
    _bintree_post_order_recursive(tree, tree->top);
}
 
void bintree_print_reverse_order(BinaryTree* tree){
    if(tree == NULL || tree->top == NULL){
        return;
    }

    _bintree_reverse_order_recursive(tree, tree->top);
}
 
bool _bintree_insert_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){

    if( tree->compare(node->data, element) < 0){
        if(node->left == NULL) {

            node->left = bintree_create_node(tree->itemSize, element);
            if(node->left == NULL)
                return false;
 
            return true;
        }
        else{
            return _bintree_insert_recursive(tree, node->left, element);
        }
    }
    else {
        if(node->right == NULL){
            node->right = bintree_create_node(tree->itemSize, element);
             
            if(node->right == NULL){
                return false;
            }
            return true;
        }
        else{
            return _bintree_insert_recursive(tree, node->right, element);
        }
    }
}
 
bool _bintree_search_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){
    int compa = tree->compare(node->data, element);
 
    if( compa == 0 ){
        return true;
    }
    else if (compa < 0 ){
        if(node->left == NULL){
            return false;
        }
        else{
            return _bintree_search_recursive(tree, node->left, element);
        }
    }
    else if (compa > 0 ){
        if(node->right == NULL){
            return false;
        }
        else{
            return _bintree_search_recursive(tree, node->right, element);
        }
    }
}
 
void _bintree_in_order_recursive(BinaryTree* tree, BinaryTreeNode* node){

    if(node->left != NULL){
        _bintree_in_order_recursive(tree, node->left);
    }
    tree->print(node->data);

    if(node->right != NULL){
        _bintree_in_order_recursive(tree, node->right);
    }
}
 
void _bintree_pre_order_recursive(BinaryTree* tree, BinaryTreeNode* node){   
    tree->print(node->data);
 
    if(node->left != NULL)
        _bintree_pre_order_recursive(tree, node->left);
     
    if(node->right != NULL)
        _bintree_pre_order_recursive(tree, node->right);
}
 
void _bintree_post_order_recursive(BinaryTree* tree, BinaryTreeNode* node){

    if(node->left != NULL)
        _bintree_post_order_recursive(tree, node->left);
 
    if(node->right != NULL)
        _bintree_post_order_recursive(tree, node->right);

    tree->print(node->data);
}
 
void _bintree_reverse_order_recursive(BinaryTree* tree, BinaryTreeNode* node){   
    if(node->right != NULL)
        _bintree_reverse_order_recursive(tree, node->right);

    tree->print(node->data);

    if(node->left != NULL)
        _bintree_reverse_order_recursive(tree, node->left);
}


void bintree_print_breadth_first(BinaryTree* tree) {

    Queue *queue = queue_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");

    BinaryTreeNode *tempNode = tree->top;

    queue_enqueue(queue, tempNode);

    while (queue_size(queue) > 0) {
        tempNode = queue_dequeue(queue);
        
        tree->print(tempNode->data);
 
        /*Enqueue left child */
        if (tempNode->left != NULL){
            queue_enqueue(queue, tempNode->left);
        }
        /*Enqueue right child */
        if (tempNode->right!=NULL){
            queue_enqueue(queue, tempNode->right);
        }
    }
}

void bintree_print_depth_first(BinaryTree* tree){

    Stack *stack = stack_initialize(sizeof(BinaryTreeNode), "BinaryTreeNode");

    BinaryTreeNode *tempNode = tree->top;

    stack_push(stack, tempNode);

    while (stack_size(stack) > 0) {

        tempNode = stack_pop(stack);

        tree->print(tempNode->data);
 
        /*push right child */
        if (tempNode->right != NULL){
            stack_push(stack, tempNode->right);
        }
        /*push left child */
        if (tempNode->left!=NULL){
            stack_push(stack, tempNode->left);
        }
    }
}

bool bintree_insert_replace(BinaryTree* tree, void* element){
    if(tree == NULL || element == NULL){
        return false;
    }

    if(tree->top == NULL) {
        tree->top = bintree_create_node(tree->itemSize, element);
        if(tree->top == NULL){
            return false;
        }
        return true;
    }


    else {
        return _bintree_insert_replace_recursive(tree, tree->top, element);  
    }
}

bool _bintree_insert_replace_recursive(BinaryTree* tree, BinaryTreeNode* node, void* element){
    if( tree->compare(node->data, element) == 0){
        if(node->left == NULL) {

            node->left = bintree_create_node(tree->itemSize, element);
            if(node->left == NULL)
                return false;
 
            return true;
        }
        else{
            return _bintree_insert_recursive(tree, node->left, element);
        }
    }
    else {
        if(node->right == NULL){
            node->right = bintree_create_node(tree->itemSize, element);
             
            if(node->right == NULL){
                return false;
            }
            return true;
        }
        else{
            return _bintree_insert_recursive(tree, node->right, element);
        }
    }
}


