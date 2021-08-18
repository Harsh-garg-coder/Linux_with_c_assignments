/*
 * Program to swap two numbers without using the third variable
 *
 * Compilation : gcc -o swap_two_numbers swap_two_numbers.c
 * Execution : ./swap_two_numbers 
 * @Harsh Garg,1910990582,07/08/2021
 * Assignement 1
 *
 */

#include<stdio.h>

int main()
{
    int a;
    int b;
   
    printf("Enter the value of a:");
    scanf("%d",&a);

    printf("Enter the value of b:");
    scanf("%d",&b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d\nb = %d\n",a,b);
}
