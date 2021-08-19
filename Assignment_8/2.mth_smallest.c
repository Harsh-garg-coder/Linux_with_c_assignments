/*
 * Program to find the mth smallest element from an array
 *
 * Compilation: gcc 2.mth_smallest.c
 * Execution: ./a.out
 * @Harsh_Garg,1910990582,19/08/2021
 * Assignement 8
 */

#include<stdio.h>

/*
 * Function that will partition an array based on the given value
 * 
 * Parameter:
 * 1. array
 * 2. starting position of array
 * 3. ending position of array
 * 4. value for partitioning
 */
int partition (int arr[], int left, int right, int value)
{
    int i = left;
    int j = left;
    
    while (i <= right)
    {
        if (arr[i] > value)
        {
            i++;
        }
        else
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
            i++;
            j++;
        }
    }
    return j-1;
}

/*
 * Function that will return the mth smallest element
 *
 * Parameter:
 * 1. an array
 * 2. starting position of the array
 * 3. end position of the array
 * 4. value of m
 */
int mth_smallest (int arr[], int left, int right, int m)
{
    int pivot = arr[right];
    
    int pivot_idx = partition(arr, left, right, pivot);
    
    if (pivot_idx == m - 1)
    {
        return arr[pivot_idx];
    }
    else if (pivot_idx < m)
    {
        return  mth_smallest(arr, pivot_idx + 1, right, m);
    }
    else
    {
        return mth_smallest(arr, left, pivot_idx - 1, m);  
    }
}
int main()
{
    int n;
    
    printf("Enter the size of the array:");
    scanf("%d", &n);

    int arr[n];
   
    printf("Enter the elements of the array:");
    
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    int m;
   
    printf("Enter the value of m:");
    scanf("%d", &m);
   
    int ans = mth_smallest(arr, 0, n - 1, m);

    printf("%d", ans);
    return 0;
}

 
