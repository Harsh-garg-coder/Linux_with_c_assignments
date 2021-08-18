/*
 * Program to fing the sign of the given number
 * 
 * Compilation: gcc sign.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,18/08/2021
 * Assignement 3
 */

#include<stdio.h>

/*
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 * Examples: sign(130) = 1, sign(-23) = -1
 * Legal ops: ! ~ & ^ | + << >>
 * Max ops : 10
 */
int sign(int x) {   
    return ((!!x) | (x >> 31));
}

int main()
{
    int x;
    
    printf("Enter the value of number:");
    scanf("%d", &x);
   
    int ans = sign(x);
    printf("%d", ans);
    return 0;
}

 
