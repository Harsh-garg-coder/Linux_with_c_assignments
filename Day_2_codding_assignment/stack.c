/*
 * Program to implement stack
 *
 * Compilation: gcc -o stack stack.c
 * Execution: ./stack 
 * @Harsh_Garg,1910990582,07/08/2021
 */

#include<stdio.h>

int stack[100];
int top = -1;

/*
 * Function that will push the values into the stack
 */
void push(int val)
{
    if(top == 99)
    {
        printf("Stack Overflow");
    }
    else 
    {
        stack[++top] = val;
    }
}

/*
 * Function that will pop the value from stack
 */
int pop()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else 
    {
        int val = stack[top];
        top--;
        return val;
    }
}

/*
 * Function that will return the value at the top of stack
 */
int peek()
{
    if(top == -1)
    {
        printf("Stack Underflow");
        return -1;
    }
    else 
    {
        return stack[top];
    }
}
    
/*
 * Function that will tell us that whether the stack is empty or not
 */
int is_empty()
{
    if(top == -1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    
    printf("%d", peek());
    return 0;
}

 
