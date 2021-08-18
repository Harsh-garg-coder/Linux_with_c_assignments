/*
 * Program to evaluate the Reverse Polish Expression
 *
 * Compilation: gcc -o reverse_polish_evaluation reverse_polish_evaluation.c
 * Execution: ./reverse_polish_evaluation
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>

/*
 * Function that will take two integers and one operator and return the result
 */
int evaluate(int value1, int value2, char operator)
{
    if(operator == '+')
    {
        return value1 + value2;
    }
    else if(operator == '-')
    {
        return value1 - value2;
    }
    else if(operator == '*')
    {
        return value1 * value2;
    }
    else 
    {
        return value1 / value2;
    }
}

int main(int no_of_arguments,char* arguments[])
{
    int stack[10000];
    int top = -1;

    for(int i = 1; i < no_of_arguments; i++)
    {
        if(arguments[i][0] >= '0' && arguments[i][0] <= '9')
        {
            stack[++top] = arguments[i][0] - '0';
        }
        else 
        { 
            char operator = arguments[i][0];
            int value2 = stack[top--];
            int value1 = stack[top--];

            int ans = evaluate(value1,value2,operator);
            stack[++top] = ans;
        }  

    }
    
    printf("%d", stack[top]);
    return 0;
}

 
