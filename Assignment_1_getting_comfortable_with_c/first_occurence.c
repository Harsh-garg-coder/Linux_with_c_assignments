/*
 * Program to find the first occurence of any character from second string in the first String
 *
 * Compilation: gcc -o first_occurence first_occurence.c
 * Execution: ./first_occurence 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>

/*
 * Function that takes two strings and return the first location on which any character of the second string is present in the first string
 *
 * Parameters:
 * 1. first string
 * 2. second string
 */
int any(char str1[], char str2[])
{
    int map[26];
    for(int i = 0; i < 26; i++)
    {
        map[i] = 0;
    }


    for(int i = 0; str2[i] != '\0'; i++)
    {
        map[str2[i] - 'a']++;  
    }

    for(int i = 0; str1[i] != '\0'; i++)
    {
        if(map[str1[i] - 'a'] != 0)
        {
            return i;
        }
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
    
    int ans = any(str1,str2);
    
    printf("%d", ans);
   
    return 0;
}

 
