/*
 * Program to count the inversions in an array
 *
 * Compilation: gcc -o inversion_count inversion_count.c
 * Execution: ./inversion_count
 * @Harsh_Garg,1910990582,15/08/2021
 * Assignement 7
 */

#include<stdio.h>

/*
 * Function that will merge two sorted halfs of the array and retrun the inversion count 
 *
 * Parameters :- 
 * 1. array
 * 2. starting point of the first sorted half
 * 3. ending point of first sorted half
 * 4. ending point of second sorted half
 */
int merge(int arr[], int left, int mid, int right)
{
    int result[right - left + 1];

    int i = left;
    int j = mid + 1;
    int k = 0;

    int count = 0;

    while(i <= mid && j <= right)
    {
        if(arr[i] < arr[j])
        {
            result[k++] = arr[i++];
        }
        else
        {
            count += mid - i + 1;
            result[k++] = arr[j++];
        }
    }
   
    while(i <= mid)
    {
        result[k++] = arr[i++];
    }
    
    while(j <= right)
    {
        result[k++] = arr[j++];
    }
    
    for(i = 0; i < right - left + 1; i++)
    {
        arr[i + left] = result[i];
    }
    
    return count; 
}

/*
 * Function that will sort the array(using merge sort) and return the inversion count
 *
 * Parameters :-
 * 1. array 
 * 2. startig index of the array
 * 3. ending index of the array
 */            
int count_inversions(int arr[], int left, int right)
{
    if(left == right)
    {
        return 0;
    }
    
    int mid = left + (right - left) / 2;

    int left_inversions = count_inversions(arr, left, mid);
    int right_inversions = count_inversions(arr, mid + 1, right);

    int my_inversions = merge(arr,left,mid,right);
   
    return my_inversions + left_inversions + right_inversions;
}
    
int main()
{
    int n;
    
    printf("Enter the no. of elements:");
    scanf("%d", &n);

    int arr[n];
   
    printf("Enter the Elements of the array:");
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
   
    int ans = count_inversions(arr, 0, n - 1);

    printf("%d", ans);

    return 0;
}

 
