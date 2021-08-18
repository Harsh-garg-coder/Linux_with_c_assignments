/*
 * Program to implement Queue
 *
 * Compilation: gcc -o queue queue.c
 * Execution: ./queue 
 * @Harsh_Garg,1910990582,07/08/2021
 */

#include<stdio.h>

int queue[1000];
int front = -1;
int rear = -1;

/*
 * Function to enter the value in the queue
 */
void enqueue(int val)
{
   if(rear == 999)
   {
       printf("Queue Overflow");
       return;
   }
 
   if(front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[front] = val;
    }
    else
    {
        queue[++rear] = val;
    }
}

/*
 * Function to remove the element from the queue
 */
int dequeue()
{
    if(front == -1)
    {
        printf("Queue Underflow");
        return -1;
    }
    else
    {
        int val = queue[front];
        front++;
        return val;
    }
}

/*
 * Function that return the front of the queue
 */
int peek()
{
    if(front == -1)
    {
        printf("Queue Underflow");
        return -1;
    }
    else 
    {
        return queue[front];
    }
}

/*
 * Function that will return 1 if queue is empty and return 0 if queue is not empty
 */
int is_empty()
{
    if(front == rear || front == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
   
    printf("%d", peek());
    return 0;
}

 
