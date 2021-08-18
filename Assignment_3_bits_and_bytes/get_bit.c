/*
 * Program to extract byte n from word x
 * 
 * Compilation: gcc get_bit.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,18/08/2021
 * Assignement 3
 */

#include<stdio.h>

/*
 * getByte - extract byte n from word x
 * Examples: getByte(0x12345678, 1)  = 0x56
 * Legal ops: ! ~ & ^| + << >>
 * Max ops: 6
 */
int getByte(int x, int n) {

    return (x >> (n << 3)) & 0xff;
}

int main()
{
    int x;
    int n;

    printf("Enter the value of number:");
    scanf("%d", &x);

    printf("Enter the value of n:");
    scanf("%d", &n);
      
    int ans = get_bit(x,n);
    printf("%d", ans);
    return 0;
}

 
