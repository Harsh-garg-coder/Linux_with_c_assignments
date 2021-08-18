/*
* rogram to return x with the n bits that begin at position p inverted
*
* Compilation: gcc invert.c
* Execution: ./a.out
* @Harsh_garg, 1910990582, 18/08/2021
* Assignment 3
*/

#include<stdio.h>

/*
 * Return x with the n bits that begin at position p inverted (i.e. turn 0 /* into 1 and vice versa)
 * and the rest left unchanged. Consider the indices of x to begin with the /* lower -order bit   numbered
 * Legal ops: ~ & ^ | << >>
 * as zero
 */
int invert(int x, int p, int n)
{
    return x ^ (((1 << n) - 1) << p);
}

int main()
{
    int x, p, n;
    scanf("%d %d %d", &x, &p, &n);

    printf("%d", invert(x, p, n));
}
