/*
 * Program to find the last occurence of second string in the first String
 *
 * Compilation: gcc -o last_occurence_occurence last_occurence.c
 * Execution: ./last_occurence 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>
#include<string.h>

/*
 * Function that will return the rightmost index of the second string in the first string
 *
 * Parameter:
 * 1. first string
 * 2. second string
 *
 */ 
int strrindex(char* str1, char* str2)
{
    int len2 = strlen(str2);
    int len1 = strlen(str1);
    
    int j = len2 - 1;
   
    for(int i = len1 - 1; i >= 0; i--)
    {
        if(j < 0)
        {
            return i+1;
        }
        if(str1[i] == str2[j])
        {
            j--;
        }
        else 
        {
            j = len2 - 1;
        }
    }
    if(j < 0)
    {
        retrun 0;
    }
     
    return -1;
}  
       
int main()
{  
    char str1[50];  
    char str2[50];

    printf("Enter the first string:");
    scanf("%s", str1);
   
    printf("Enter the second string:");
    scanf("%s", str2);
  
    int ans = strrindex(str1, str2);

    printf("%d", ans);
 
    return 0;
}
 
