/*
 * Program to implement stack using queues
 *
 * Compilation: gcc -o stack_using_queues stack_using_queues.c
 * Execution: ./stack_using_queues
 * @Harsh_Garg,1910990582,17/08/2021
 * Assignment 4
 */

#include<stdio.h>
#include<stdlib.h>

//implementing queue
struct queue
{
    int* arr;
    int front;
    int rear;
    int capacity; 
};


/*
 * Function that will return 1 if the queue is full
 *
 * Parameters:
 * 1. Pointer to the queue
 */
int is_full(struct queue* q)
{
    if ( (q->rear + 1) % q->capacity == q->front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/* 
 * Function that add value in queue
 *
 * Paramters:
 * 1. Pointer to the queue
 * 2. value to be added
 */
void enqueue(struct queue* q, int val)
{
    if(is_full(q) == 1)
    {
        int * new_arr = (int*) malloc( sizeof(int) * q->capacity * 2);
        
        for(int i = 0; i < q->capacity; i++)
        {
            new_arr[i] = q->arr[i];
        }
      
        q->arr = new_arr;
        q->capacity = q->capacity * 2; 
        
        q->arr[ (q->rear + 1) % q->capacity ] = val;
        q->rear = (q->rear + 1 ) % q->capacity;
    }
    else  if (q->front == -1 && q->rear == -1)
    {
        q->front = q->rear = 0;
        q->arr[q->rear] = val;
    }
    else
    {
        q->arr[ (q->rear + 1) % q->capacity ] = val;
        q->rear = (q->rear + 1 ) % q->capacity;
    }    
}

/*
 * Function that will return 1 if the queue is empty
 *
 * Paramters:
 * 1. Pointer to the queue
 */
int is_empty(struct queue* q)
{
    if (q->front == -1 && q->rear == -1)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
 
/* 
 * Function to remove value from the queue
 *
 * Parameter:
 * 1. Pointer to the queue
 */
void dequeue(struct queue* q)
{
    if(is_empty(q))
    {
        return;
    }
    else if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        q->front = ( q->front + 1 ) % q->capacity;
    }
}

/*
 * Function that will return the value at the front of the queue
 *
 * Parameters:
 * 1. Pointer to the queue
 */
int peek(struct queue* q)
{
    if(is_empty(q))
    {
        return -1;
    }
    else
    {
        return q->arr[ q->front ];
    }
}

//implementing stack using queue
struct stack
{
    struct queue* mq;
    struct queue* hq;
};

void push(struct stack* st, int val)
{
    if(is_empty(st->mq))
    {
        enqueue(st->mq, val);
    }
    else
    {
        while( !is_empty(st->mq) )
        {
            int data = peek(st->mq);
            enqueue(st->hq, data);   
            dequeue(st->mq);
        }
      
        enqueue(st->mq, val);
        
        while( !is_empty(st->hq) )
        {
            int data = peek(st->hq);
            enqueue(st->mq, data);
            dequeue(st->hq);
        }
    }
}

/*
 * Function that will remove the value from the stack
 *
 * Parameters:
 * 1. Pointer to the stack
 */
void pop(struct stack* st)
{
    if ( is_empty(st->mq))
    {
        return;
    }
    else
    {
        dequeue(st->mq);
    }
}

/* 
 * Function that will return the value at the top of the stack
 *
 * Parameter:
 * 1. Pointer to the stack
 */
int top(struct stack* st)
{
    if ( is_empty(st->mq) )
    {
        printf("Stack underflow");
        return -1;
    }
    else
    {
        return peek(st->mq);
    }
}

/*
 * Function that will return 1 if the stack is empty and 0 if the stack is not empty
 *
 * Parameters:
 * 1. Pointer to the stack
 */
int is_empty_stack(struct stack* st)
{
    return is_empty(st->mq);
}

int main()
{
    struct stack* st = (struct stack*) malloc( sizeof(struct stack*) );
    
    st->mq = (struct queue*) malloc( sizeof(struct queue*) );
    st->hq = (struct queue*) malloc( sizeof(struct queue*) );

    st->mq->front = st->mq->rear = st->hq->front = st->hq->rear = -1;
    st->mq->capacity = st->hq->capacity = 20;

    st->mq->arr = (int*) malloc( sizeof(int) * st->mq->capacity );
    st->hq->arr = (int*) malloc( sizeof(int) * st->hq->capacity );

    push(st, 10);   
    push(st, 20);   
    push(st, 30);   
    push(st, 40);   
    push(st, 50);

    printf("%d\n", top(st) );
    pop(st);   

    printf("%d\n", top(st) );
    pop(st);
    
    printf("%d\n", top(st) );
    pop(st);
 
    printf("%d\n", top(st) );
    pop(st);
 
    printf("%d\n", top(st) );
    pop(st);
   
    return 0;
}
 
