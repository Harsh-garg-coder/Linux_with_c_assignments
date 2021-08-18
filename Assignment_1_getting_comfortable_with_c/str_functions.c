/*
 * Program to implement strncpy, strncat and strncmp
 *
 * Compilation: gcc -o str_function str_functions.c
 * Execution: ./str_functions 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>

/* 
 * Function to copy first n chracter of second string to the beginning of the first string
 *
 * Parameters:
 * 1. first string
 * 2. second string
 * 3. no. of characters to be copied
 */
void strncpy(char* str1, char* str2, size_t  n)
{
    for(int i = 0; i < n; i++)
    {
        if(str1[i] == '\0' || str2[i] == '\0')
        {
            return;
        }
        else
        {
            str1[i] = str2[i];
        }
    }
}

/* 
 * Function to concatenate first n chracter of second string to the end of the first string
 *
 * Parameters:
 * 1. first string
 * 2. second string
 * 3. no. of characters to be concatenated
 */
void strncat(char* str1, char * str2, size_t n)
{
    int j = 0;
    for(j = 0; str1[j] != '\0'; j++)
    {
        continue;    
    }
 
    for(int i = 0; str2[i] != '\0'; i++)
    {
        str1[j++] = str2[i];
    }

    str1[j] = '\0';
}

/* 
 * Function that will compare first n characters of two given string and retrun:
 * +ve value -> if the second string is smaller than the first string
 * -ve value -> if the first string is smaller than the second string
 * 0 -> if both the strings are equal
 * 
 * Parameters:
 * 1. first string
 * 2. second string
 * 3. no. of characters to be compared
 */
int strncmp(char* str1, char* str2, size_t n)
{
    for(int i = 0; i < n; i++)
    {
        if(str1[i] < str2[i])
        {
            return -1;
        }
        else if(str1[i] > str2[i])
        {
            return 1;
        }
    }
    return 0;
}
     
int main()
{
    char str1[20];
    char str2[20];

    printf("Enter the first String:");
    scanf("%s", str1);

    printf("Enter the second string:");
    scanf("%s", str2);
   
    int n;

    printf("Enter the value of n:");
    scanf("%d", &n);

    strncpy(str1, str2, n);
    printf("First string after the execusion of strncpy function: %s",str1);

    strncat(str1, str2, n);
    printf("\nFirst string after the execusion of strncat function: %s",str1);

    int ans = strncmp(str1, str2, n);
    
    printf("\n%d", ans);

    return 0;
}

 
