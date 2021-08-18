/* 
 * Program to reverse the string
 *
 * Compilation: gcc -o reverse_string reverse_string.c
 * Execution: ./reverse_string
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignement 1
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char str[80];
   
    printf("Enter the String:");
    gets(str);

    int left = 0;
    int right = strlen(str) - 1;
   
    while(left < right)
    {
        char temp = str[left];
        str[left] = str[right]; 
        str[right] = temp;
        left++;
        right--;
    }
   
    printf("%s", str);

    return 0;
}

 
