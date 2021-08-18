/*
 * Program to find the largest area of histogram
 * 
 * Compilation: gcc -o largest_area_histogram largest_area_histogram.c
 * Execution: ./largest_area_histogram
 * @Harsh_Garg, 1910990582, 18/08/2021
 * Assignment 4
 */

#include<stdio.h>

int stack[10000];
int top = -1;

/*
 * Function that will return 1 if the stack is empty and 0 if not empty 
 */
int is_empty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

/*
 * Function that will push the given value in the stack
 *
 * Paramters:
 * 1. value to be pushed
 */
void push(int item)
{
    if(top + 1 == 10000)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top] = item;
    }
}

/*
 * Function that will remove an element from the stack and return the removed value
 */
int pop()
{
    int y;
    if(is_empty())
    {
        printf("Stack Underflow");
    }

    y = stack[top];
    top--;
    return y;
}

/*
 * Function that will return the top of the stack
 */
int peek()
{
    return stack[top];
}

/*
 * Function that will return the max value of two given values
 *
 * Paramters:
 * 1. first value
 * 2. second value;
 */
int max(int a, int b)
{
    if(a > b)
        return a;
    else
        return b;
}

/*
 * Function that will return the largest area of the histogram
 *
 * Parameters:
 * 1. an array
 * 2. size of the array
 */ 
int largest_area_rectangle(int* heights, int size){
    int ans = 0;
    for (int i = 0; i <= size; i++)
    {
        int x;
        if(i == size)
        {
            x = 0;
        }
        else
        {
            x = heights[i];
        }

        while (!is_empty() && heights[peek()] >= x)
        {
            int curr = pop();
            int next_bar = i - 1;
            int prev_bar;
           
            if ( is_empty() )
            {
                prev_bar = 0;
            }
            else
                prev_bar = peek() + 1;
            
            int max_area = heights[curr] * (next_bar - prev_bar + 1);
             
            if (max_area > ans)
                ans = max_area;
        }
        
        if (i != size)
            push(i);
    }
    return ans;
}

int main()
{
    int n;
    
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the values of the array:");
   
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
  
    int ans = largest_area_rectangle(arr, n);
   
    printf("Largest Area of Rectangles is %d", ans);
  
    return 0;
}
