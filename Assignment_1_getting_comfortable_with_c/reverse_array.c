/*
 * Program to reverse the Array
 *
 * Compilation: gcc -o reverse_array reverse_array.c
 * Execution: ./reverse_array 
 * @Harsh_Garg,1910990582,02/08/2021
 * Assignement 1
 */

#include<stdio.h>

int main()
{
    int n;

    printf("Enter the size of the Array:");
    scanf("%d",&n);

    int arr[n];
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
   
    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
       
        left++;
        right--;
    }

    for(int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    return 0;
}

 
