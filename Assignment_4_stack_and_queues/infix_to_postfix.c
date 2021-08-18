/*
 * Program to convert infix Expression into postfix expression
 *
 * Compilation: gcc -o infix_to_postfix infix_to_postfix.c
 * Execution:./infix_to_postfix
 *
 * @Harsh_Garg, 1910990582, 18/08/2021
 * Assignment 4
 */

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXSIZE 100
int stack[MAXSIZE];
int top = -1;

/*
 * Function that will return 1 if the stack is empty and 0 if the stack is not empty
 */
int is_empty()
{
    if( top == -1 )
	return 1;
    else
	return 0;
}

/* 
 * Function that will push an element into the stack
 *
 * Parameters:
 * 1. value to be pushed
 */
void push(int item)
{
    if( top + 1 == MAXSIZE )
    {
        printf("Stack Overflow");
    }
    top++;
    stack[top] = item;
}

/*
 * Function that will pop an element from the stack
 */
int pop()
{
    if(is_empty())
    {
        printf("Stack Underflow");
    }
    int y = stack[top];
    top--;
    return y;
}

/*
 * Function to return the precedence of an operator
 */
int prec( char c )
{
    if( c == '*' || c == '/' )
	return 2;
    else if( c == '+' || c == '-' )
	return 1;
    else
	return -1;
}

/* 
 * Function that will return the element from the top of the stack
 */
int peek()
{
    return stack[top];
}

/*
 * Function To Convert Infix Expression To Postfix
 * Experssion
 */
void infix_to_postfix(char *exp)
{
    int k = -1;
    int i;
    for (i = 0, k = -1; exp[i]; i++)
    {
        if (isdigit(exp[i]))
            exp[++k] = exp[i];
         
        else if (exp[i] == '(')
            push(exp[i]);
        
        else if (exp[i] == ')')
        {
            while (!is_empty() && peek() != '(')
                exp[++k] = pop();
            pop();
        }
        else // when operator is there
        {
            while (!is_empty() && prec(exp[i]) <= prec(peek()))
                exp[++k] = pop();
            push(exp[i]);
        }
 
    }
    while (!is_empty())
        exp[++k] = pop();

    exp[++k] = '\0';
    puts(exp);
}

int main()
{
    char str[MAXSIZE];
    printf("Enter Expression : ");
    gets(str);
    infix_to_postfix(str);

}
