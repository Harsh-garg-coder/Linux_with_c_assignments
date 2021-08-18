/*
 * Program to count the no. of vowels and consonants in the given String
 * 
 * Compilation: gcc -o count_vowels_and_consonants count_vowel_and_consonants.c
 * Execution: ./count_vowels_and_consonants 
 * @Harsh_Garg,1910990582,02/08/2021
 * Assignement 1
 */

#include<stdio.h>
#include<string.h>

int main()
{
    char str[20];
    
    printf("Enter the String:");
    gets(str);
    
    int vowel_count = 0;
    int consonant_count = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        char ch = str[i];

        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'O':
            case 'U':
            case 'I':                        
                         vowel_count++;
                         break;
            default:
                         consonant_count++;
        }
    }
    
    printf("Vowels= %d, Consonants=%d\n",vowel_count,consonant_count);
  
    return 0;
}

 
