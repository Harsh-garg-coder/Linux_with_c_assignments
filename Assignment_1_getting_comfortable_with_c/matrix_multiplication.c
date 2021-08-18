/*
 * Program to Multiply the given two matrix
 *
 * Compilation: gcc -o matrix_multiplication matrix_multiplication.c
 * Execution: ./matrix_multiplication 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignement 1
 */

#include<stdio.h>

int main()
{
    int size;

    printf("Enter the size of the matrices:");
    scanf("%d", &size);

    int matrix1[size][size];
    int matrix2[size][size];

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
   
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
  
    int result[size][size];
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            result[i][j] = 0;
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            for(int k = 0;k < size; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    
 
    return 0;
}

 
