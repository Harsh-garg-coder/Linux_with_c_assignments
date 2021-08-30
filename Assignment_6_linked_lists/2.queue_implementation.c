/*
 * Program to implement Queue using linked lists
 *
 * Compilation: gcc 2.implementing_Queue.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,21/08/2021
 * Assignement 6
 */

#include<stdio.h>
#include<stdlib.h>

//implementing linked lists
struct Node
{
    int data;
    struct Node* next;
};

//implementing Queue using linked list
struct queue
{
    struct Node* front;
    struct Node* rear;
};

/*
 * Function that will return 1 if the queue is empty
 * and 0 if the queue is not empty 
 *
 * Parameters:
 * 1. Pointer to the queue
 */
int is_empty ( struct queue* q) {
    return q->front == NULL;
}

/* 
 * Function that will add a value in the queue
 *
 * Paramters:
 * 1. Pointer to the queue
 * 2. value to be inserted
 */
void enqueue (struct queue* q, int val) {
    if ( is_empty(q) ) {
        q->front = q->rear = (struct Node*) malloc( sizeof(struct Node*) );
        q->front->data = val;
        q->front->next = NULL;
    }
    else {
        struct Node* ptr = (struct Node*) malloc( sizeof(struct Node*) );
        ptr->data = val;
        ptr->next = NULL;
        q->rear->next = ptr;
        q->rear = ptr;
    }
}

/*
 * Function that will remove an element from the queue
 * and return the value if present otherwise return -1
 *
 * Parameters:
 * 1. Pointer to the queue
 */
int dequeue (struct queue* q) {
    if ( is_empty(q) ) {
        printf("Queue underflow");
        return -1;
    }
    else {
        int val = q->front->data;
        struct Node* ptr = q->front;
        q->front = q->front->next;
        free(ptr);
        return val;
    }
}

/*
 * Function that will return the element at the front of the queue
 * 
 * Parameter:
 * 1. Pointer to the queue
 */
int peek (struct queue* q) {
    if ( is_empty(q) ) {
        printf("Queue underflow");
        return -1;
    }
    else {
        return q->front->data;
    }
}

int main()
{
    struct queue* q;
    
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    printf("%d ", dequeue(q));
    
    return 0;
}

 
