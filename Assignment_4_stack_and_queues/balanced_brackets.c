/*
 * Program which checks that whether the sequence of brackets in the given string is balanced or not
 *
 * Compilation: gcc -o balanced_brackets balanced_brackets.c
 * Execution: ./balanced_brackets
 * @Harsh_Garg,1910990582,17/08/2021
 * Assignment 4
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// creating stack
struct stack{
    char* arr;
    int capacity;
    int top;
};


/*
 * Function that will push the value in the stack
 *
 * Parameters:
 * 1. Pointer to the stack
 * 2. value to be pushed
 */
void push(struct stack* st, char val)
{
    st->arr[ ++st->top ] = val;
}


/*
 * Function that will pop the element from the stack
 * 
 * Parameters:
 * 1. Pointer to the stack
 */
void pop(struct stack * st)
{
    if(st->top == -1)
    {
        return;
    }
    st->top--;
}


/*
 * Function that will tell us that whether the stack is Empty or not
 *
 * Paramters:
 * 1. Pointer to the stack
 */
int is_empty(struct stack* st)
{
    if(st->top == -1)
    {
        return 1;
    }
    return 0;
}


/*
 * Function that will return the value at the top of the stack
 *
 * Paramter:
 * 1. Pointer to the stack
 */
char top(struct stack* st)
{
    if(st->top == -1)
    {
        return '\0';
    }
    return st->arr[st->top];
}

/*
 * Function that will return 1 if the pair of the bracket is balanced
 *
 * Paramter:
 * 1. pointer to the stack
 * 2. opening bracket
 */
int is_valid_pair ( struct stack* st, char opening_bracket)
{
    if(is_empty(st))
    {
        return 0;
    }
    else if (top(st) == opening_bracket)
    {
        pop(st);
        return 1;
    }
    else
    {
        return 0;
    }
}
        
/*
 * Function that will return 1 if the sequence of the brackets is balanced otherwise return 0
 *
 * Paramters:
 * 1. sequence of the brackets
 */
int is_balanced(char str[])
{
    struct stack* st = (struct stack*) malloc( sizeof(struct stack*) );
    st->top = -1;
    st->capacity = strlen(str);
    st->arr = (char *) malloc( sizeof(char) * st->capacity);
  
    for(int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];
        
        if (ch == '(' || ch == '{' || ch == '[')
        {
            push(st,ch);
        }
        else if (ch == ')') 
        {
            int temp_ans = is_valid_pair(st, '(');
            if(temp_ans == 0)
            {
                return 0;
            }
        }
        else if (ch == '}')
        {
            int temp_ans = is_valid_pair(st, '{');
            if (temp_ans == 0)
            {
                return 0;
            }
        }
        else if (ch == ']')
        {
            int temp_ans = is_valid_pair(st, '[');
            if (temp_ans == 0)
            {
                return 0;
            }
        }
    }
    
    if (!is_empty(st))
    {
        return 0;
    }
    
    return 1;
}
        
int main()
{ 
    char str[1000];

    printf("Enter the String:");
    scanf("%s", str);

    int ans = is_balanced(str);

    if (ans == 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
 
    return 0;
}

 
