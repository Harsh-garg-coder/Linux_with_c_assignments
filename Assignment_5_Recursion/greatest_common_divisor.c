/*
 * Program to find the greatest common divisor of two numbers
 *
 * Compilation: gcc -o greatest_common_divisor greatest_common_divisor.c
 * Execution: ./greatest_common_divisor 
 * @Harsh_Garg,1910990582,06/08/2021
 * Assignement 5
 */

#include<stdio.h>

/*
 * Function to find the greatest common divisor of the two given numbers
 *
 * Parameter:
 * Two numbers to find there greatest common divisor
 */
int greatest_common_divisor(int first_no, int second_no)
{
    if(second_no == 0)
    {
        return first_no;
    }
    
    return greatest_common_divisor(second_no, first_no % second_no);
}

int main()
{
    int first;
    int second;

    printf("Enter the value of the first number:");
    scanf("%d", &first);
   
    printf("Enter the value of the second number:");
    scanf("%d", &second);
    
    int gcd = greatest_common_divisor(first,second);

    printf("Greatest Common divisor of %d and %d is %d",first,second,gcd);
    return 0;
}

 
