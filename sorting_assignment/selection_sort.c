/*
 * Program which computes the time taken by the Selection sort in different types of inputs
 *
 * Compilation: gcc -o selection_sort selection_sort.c
 * Execution: ./selection_sort 
 * @Harsh_Garg,1910990582,31/7/2021
 * Assignement 1
 */

#include<stdio.h>
#include<stdlib.h>
#include <sys/time.h>


void selection_sort(int arr[],int size);
void swap(int arr[], int left, int right);

/*
 * Fuction that will reverse the array
 * 
 * Parameter:
 * an integer array : to be reverse
 * an integer left : starting index of the array
 * an integer right : ending index of the array
 */

void reverse ( int arr[], int left, int right )
{
    while( left < right )
    {
        swap(arr, left, right);
        left++;
        right--;
    }
}  

/*
 * Fuction that will fill the array with the desired input
 * 
 * Parameter:
 * an integer array : in which we want to fill the values
 * an integer size : indicating the size of the array
 * an integer order : which will tell us that in which order we want to fill the array(0->Random values, 1->Ascending order, 2->decending order)
 */
void generate_input (int arr[], int size, int type)
{
    for(int i=0; i < size; i++)
    {
        arr[i] = rand() % size + 1;
    }
    if(type == 1)
    {
        selection_sort (arr, size);
    }
    else if(type == 2)
    {
        selection_sort (arr, size);
        reverse (arr, 0, size-1);
    }
}

/*
 * Function that will swap the two elements of the given array 
 * 
 * Parameters:
 * 1. an integer array
 * 2. two position two swap
 */
void swap (int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
 *Function that will sort the array using Selection sort algorithm
 *
 * Parameter:
 * 1. an integer array to sort
 * 2. size of the array
 */
void selection_sort (int arr[], int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min = i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        if(min != i)
        {
            swap(arr,min,i);
        }
    }
}

 
/*
 * Function that will print the time taken by the selection sort for:
 * 1. different sizes of input and
 * 2. when the elements are placed randomly
 * 
 * Parameters:
 * 1. the initail size of the array for which we want to test our algorithm
 * 2. the increment size 
 */
void random_elements_report(int initial_input_size,int increment)
{
    struct timeval te;
    
    printf("\n");
 
    for(int i=0; i < 8; i++)
    {
        int new_size = initial_input_size + increment * i;
        
        int arr[new_size];
        
        generate_input(arr,new_size,0);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        selection_sort(arr,new_size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("Time taken to sort the random input:\t %lld\n",end - start);
    }
}
        

/*
 * Function that will print the time taken by the selection sort for:
 * 1. different sizes of input and
 * 2. when the elements are placed in ascending order
 * 
 * Parameters:
 * 1. the initail size of the array for which we want to test our algorithm
 * 2. the increment size 
 */
void ascending_elements_report (int initial_input_size, int increment)
{
    struct timeval te;
    
    printf("\n");
    
    for(int i=0; i < 8; i++)
    {
        int new_size = initial_input_size + increment * i;
        
        int arr[new_size];
        
        generate_input(arr,new_size,1);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        selection_sort(arr,new_size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

       printf("Time taken to sort the elements present in Ascending order:\t %lld\n",end - start);
    }
}


/*
 * Function that will print the time taken by the selection sort for:
 * 1. different sizes of input and
 * 2. when the elements are placed in decreasing order
 * 
 * Parameters:
 * 1. the initail size of the array for which we want to test our algorithm
 * 2. the increment size 
 */
void descending_elements_report(int initial_input_size,int increment)
{
    struct timeval te;
    
    printf("\n");
 
    for(int i=0; i<8; i++)
    {
        int new_size = initial_input_size + increment * i;
        
        int arr[new_size];
        
        generate_input(arr,new_size,2);

        gettimeofday(&te, NULL);
        long long start = te.tv_sec * 1000LL + te.tv_usec / 1000;

        selection_sort(arr,new_size);

        gettimeofday(&te, NULL);
        long long end = te.tv_sec * 1000LL + te.tv_usec / 1000;

       printf("Time taken to sort the elements which are present in descending order:\t %lld \n",end - start);
    
    }
}

int main()
{
    int initial_size_of_input = 8000;
    int increment = 4000;
    
    printf("Starting..");
   
    random_elements_report(initial_size_of_input,increment);
    printf("\n");
   
    ascending_elements_report(initial_size_of_input,increment);
    printf("\n");

    descending_elements_report(initial_size_of_input,increment);
    printf("\n");
    
    

    return 0;
}

 
