/*
 * Program to do bit and using bit or and bit not
 *
 * Compilation: gcc bit_and.c
 * Execution: ./bit_and
 * @Harsh_Garg,1910990582,18/08/2021
 * Assignment 3
 */

#include<stdio.h>

/*
 * Function that will return the bitwise and of two given numbers
 *
 * Parameters:
 * Two numbers to perform operation on them
 */
int bit_and (int first_number, int second_number)
{
    return ~(~first_number | ~second_number);
}

int main()
{
    int first_number;
    int second_number;

    printf("Enter the value of first number:");
    scanf("%d", &first_number);

    printf("Enter the value of second number:");
    scanf("%d", &second_number);

    int ans = bit_and(first_number, second_number);
   
    printf("%d", ans);

    return 0;
}

 
