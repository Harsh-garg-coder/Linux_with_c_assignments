/*
 * Program to do bitwise xor using bitwise and and bitwise not
 *
 * Compilation: gcc bit_xor.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,18/08/2021
 * Assignment 3
 */

#include<stdio.h>

/*
 * Function that will return the bit xor of two numbers
 */
int bit_xor ( int first_number, int second_number)
{
    return ~(~first_number & ~second_number) & ~(first_number & second_number);
}

int main()
{
    int first_number;
    int second_number;

    printf("Enter the first number:");
    scanf("%d", &first_number);
     
    printf("Enter the second number:");
    scanf("%d", &second_number);

    int ans = bit_xor(first_number,second_number);
    
    printf("%d", ans);
    return 0;
}

 
