/*
 * Program to print n numbers in fibonnacci series that are even
 *
 * Compilation: gcc 1.fibo.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,19/08/2021
 * Assignement 8
 */

#include<stdio.h>

/*
 * Function that will print n fibonacci numbers that are even
 */
void print_fibo(int n) {
    int first = 0;
    int second = 2;
    
    if(n == 1)
    {
        printf("0");
    }
    else if(n == 2)
    {
        printf("0 2");
    }
    else
    {
        printf("0 2 ");
        int count = 2;
        while(count < n)
        {
            int third = first + 4 * second;
            first = second;
            second = third;
        
            printf("%d ", third);
            count++;
        }
    }
}

int main()
{
    int n;
    
    printf("Enter the value of n:");
    scanf("%d", &n);

    print_fibo(n);
    return 0;
}

 
