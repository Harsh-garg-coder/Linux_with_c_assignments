/*
 * Program to print the pyramid with given no. of lines
 *
 * Compilation: gcc -o print_pyramid print_pyramid.c
 * Execution: ./print_pyramid 
 * @Harsh_Garg,1910990582,02/08/2021
 * Assignement 1
 */

#include<stdio.h>

int main()
{
    int n;
    
    printf("Enter the no. of lines:");
    scanf("%d",&n);
   
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        for(int j = 1; j <= i; j++)
        {
            printf("# ");
        }
        printf("\n");
    }  

    return 0;
}

 
