/*
 * Program to squeeze the string
 *
 * Compilation: gcc -o squeeze squeeze.c
 * Execution: ./squeeze 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
 */

#include<stdio.h>
#include<string.h>

void squeeze(char str1[], char str2[])
{
    int len = strlen(str1);
    int map[26];
   
    for(int i = 0; i < 26; i++)
    {
        map[i] = 0;
    }


    for(int i = 0; str2[i] != '\0'; i++)
    {
        map[str2[i] - 'a']++;  
    }
    
    int count = 0;

    for(int i = 0; str1[i] != '\0'; i++)
    {
        if(map[str1[i] - 'a'] != 0)
        {
            for(int j = i; str1[j + 1] != '\0'; j++) 
            {
                str1[j] = str1[j+1];
            }
            count++;
            i--;
        }
    }
    
    str1[len - count] = '\0';
}

    
int main()
{  
    char str1[50];  
    char str2[50];

    printf("Enter the first string:");
    scanf("%s", str1);
   
    printf("Enter the second string:");
    scanf("%s", str2);
   
    squeeze(str1,str2); 
    
    printf("%s",str1);
    return 0;
}

 
