/*
 * Program to implement stack using linked listd
 *
 * Compilation: gcc 1.stack_implementation.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,19/08/2021
 * Assignement 6
 */

#include<stdio.h>
#include<stdlib.h>

//implementation of linked list
struct Node {
    int data;
    struct Node* next;
};

/*
 * Function that will push the value in the front of the  
 * linked list and return the head of the new linked list
 * 
 * Parameters:
 * 1. pointer to the head of the linked list
 * 2. value to be inserted
 */
struct Node* push (struct Node* head, int val) {
    struct Node* ptr = (struct Node*) malloc( sizeof(struct Node*) );
    ptr->data = val;
    ptr->next = head;
   
    return ptr;
}

/*
 * Function that will remove the element from the linked list
 * and return the head of the new linked list
 *
 * Parameter:
 * 1. pointer to the head of the linked list
 */
struct Node* pop (struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    else {
        struct Node * new_head = head->next;
        free(head);
        return new_head;
    }
}

/*
 * Function that will return 1 if the stack
 * is empty and 0 if the stack is not empty
 *
 * Parameters:
 * 1. Pointer to the head of the linked list
 */
int is_empty (struct Node* head) {
    return head == NULL;
}

/*
 * Function that will return the value at the
 * top of the stack and if the stack is empty 
 * return -1
 *
 * Parameters:
 * 1. Pointer to the head of the linked list
 */
int peek (struct Node* head) {
    if (head == NULL) {
        return -1;
    }
    else {
        return head->data;
    }
}
 
int main()
{
    struct Node* head = NULL;
   
    head = push(head, 10);
    head = push(head, 20);
    head = push(head, 30);

    printf("%d ", peek(head));
    head = pop(head);    
    
    printf("%d ", peek(head));
    head = pop(head);
    
    printf("%d ", peek(head));
    head = pop(head);
    
    return 0;
}

 
