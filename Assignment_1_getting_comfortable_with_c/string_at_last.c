/*
 * Program to find that whether second string is present at the last of the first string or not
 *
 * Compilation: gcc -o string_at_last string_at_last.c
 * Execution: ./string_at_last 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>
#include<string.h>

/*
 * Function what will return :
 * 1 -> if the second string is present at the end of the first string
 * 0 -> if the second string is not present at the end of the first string
 *
 * Parameters:
 * 1. first string
 * 2. second string
 */ 
int strend(char* str1, char* str2)
{
    int len2 = strlen(str2);
    int len1 = strlen(str1);
    
    int j = len2 - 1;
   
    if(len1 < len2)
    {
        return 0;
    }
    for(int i = len1 - 1; i >= 0; i--)
    { 
        if(j < 0)
        {
            return 1;
        }

        if(str1[i] != str2[j])
        {
            return 0;
        }
        else
        {
            j--;
        }
    }
}
    
int main()
{  
    char str1[50];  
    char str2[50];

    printf("Enter the first string:");
    scanf("%s", str1);
   
    printf("Enter the second string:");
    scanf("%s", str2);
   
    int ans = strend(str1,str2);

    printf("%d", ans);
 
    return 0;
}
 
