/*
 * Program to implement deque using linked list.
 *
 * Compilation: gcc deque_implementation.c
 * Execution:./a.out
 *
 * @Harsh_Garg, 1910990582 , 30/08/2021
 * Assignment 6
 */ 

#include<stdlib.h>
#include<stdio.h>

// linked list implementation
struct list{
    int data;
    struct list* next;
}*ptr = NULL, *temp = NULL, *rear = NULL, *front = NULL;

/*
 * Function that will make a new Node
 */
struct list* NewNode()
{
    struct list* node;
    node = (struct list*)malloc(sizeof(struct list));
    node -> data = 0;
    node -> next = NULL;
}
	
// function to delete element from front
int delete_front()  
{
    int item;
    if(front == NULL)
    {
	printf("\nQueue Underflow");
	exit(1);
    }
    temp = front;
    item = temp -> data;
    front = front -> next;
    free(temp);
    return item;
}
	
// function to insert element at front
void insert_front(int item)  
{
    struct list* node = NewNode();
    node -> data = item;
    if(front == NULL)
    {
	front = node;
	rear = node;
		
    }
    else
    {
	rear -> next = node;
	rear = node;
    }
}
	
// function to delete element from last
int delete_last()     
{
    struct list* temp;
    ptr = front;
    if(front == rear)
    {
        free(front);
    	front = NULL;
 	rear = NULL;
    }
    while(ptr -> next != rear)
    {
	ptr = ptr-> next;
    }
    temp = rear;
    rear = ptr;
    ptr->next=NULL;
    free(temp);
}
	
// function to insert element at last
void insert_last(int item)
{
    struct list* node = NewNode();
    node -> data = item;
    if(front==NULL)
    {
        front = node;
	rear = node;
	return;
    }
    node -> next = front;
    front = node;
}
	
// function to print deque
void print()
{
    if(front == NULL)
    {
        printf("\nQueue is empty\n");
	return;
    }
    ptr = front;
    printf("\n\nPrinting Deque\n\n");
    while(ptr)
    {
	printf("%d->",ptr -> data);
	ptr = ptr -> next;
    }
    printf("NULL\n");
}

int main()
{
    insert_front(10);
    insert_front(20);
    insert_front(30);
    print();
    delete_front();
    print();
    insert_last(40);
    insert_last(50);
    delete_last();
    print();
}
