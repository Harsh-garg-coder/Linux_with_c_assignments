/*
 * Program to check whether the given string is palindrome or not
 *
 * Compilation: gcc -o is_palindrome is_palindrome.c
 * Execution: ./is_palindrome 
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignement 1
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char str[20];
    
    gets(str);
    
    int len = strlen(str);

    int left = 0;
    int right = len - 1;
    
    while(left < right)
    {
        if(str[left] == ' ')
        {
            left++;
        }
        if(str[right] == ' ')
        {
            right--;
        }
      
        if(str[left] == str[right] || str[left] + 32 == str[right] || str[left] == str[right] + 32)
        {
            left++;
            right--;
            continue;
        }
        else
        {
            printf("false");
            return 0;
        }
    }
  
    printf("true");
    
    return 0;
}

 
