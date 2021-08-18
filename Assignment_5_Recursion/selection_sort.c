/*
 * Program to sort an Array using selection sort using recursion
 *
 * Compilation: gcc -o selection_sort selection_sort.c
 * Execution: ./selection_sort 
 * @Harsh_Garg,1910990582,06/08/2021
 * Assignement 5
 */

#include<stdio.h>

/* 
 * Function to sort the Array using selection sort using recurison
 *
 * Parameters:
 * 1. an array to be sorted
 * 2. current position of the array for which we are finding the correct element
 * 3. size of the Array
 */
void selection_sort(int arr[], int idx, int size)
{ 
    if(idx == size - 1)
    {
        return;
    }

    int min = idx;

    for(int j = idx + 1; j < size; j++)
    {
        if(arr[min] > arr[j])
        {
            min = j;
        }
    }
   
    if(min != idx)
    {
        int temp = arr[min];
        arr[min] = arr[idx];
        arr[idx] = temp;
    }
   
    selection_sort(arr, idx + 1, size);
}
     
int main()
{
    int n;

    printf("Enter the size of the Array:");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
   
    selection_sort(arr,0,n);

    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
 
    return 0;
}

 
