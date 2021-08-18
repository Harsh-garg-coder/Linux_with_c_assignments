/*
 * Program to print n times the every third element of the fibonacci series.
 *
 * Compilation: gcc -o fibonacci fibonacci.c
 * Execution: ./fibonacci 
 *
 * @Harsh_Garg,1910990582,06/08/2021
 * Assignement 5
 */

#include<stdio.h>

/*
 * Function to print every third element of the fibonacci series n times
 *
 * Parameters: 
 * an integer denoting the no. of times we want to print the third element of the fibonacci series
 */

void fibo(int n)
{    
    int dp[n * 3 + 1];
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n * 3; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
   
    for(int i = 3; i <= n * 3; i += 3)
    {
        printf("%d ",dp[i]);
    }
}
int main()
{
    int n;

    printf("Enter the value of n:");
    scanf("%d",&n);

    fibo(n);
   
    return 0;
}

 
