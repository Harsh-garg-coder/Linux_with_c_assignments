/*
 * Program to print all the input lines that are longer than 80 characters
 * 
 * Compilation: gcc -o print_lines_longer_than_80 print_lines_longer_than_80.c
 * Execution: ./print_lines_longer_than_80
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignment 1
*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    char file_name[1000];

    printf("Enter the file name:\n");
    scanf("%s", file_name);

    FILE *ptr = fopen(file_name, "r");

    if (!file_name)
    {
        printf("File could not be opened\n");
        return 0; 
    }

    char input[1000]; 

    while (fscanf(ptr, "%[^\n]%*c", input) != EOF)
    {
        //finding the length of the string
        int length = 0;
        
        while (input[length] != '\0')
        {
            length++;
        }

        //if length of string is greater than 80, then printing it
        if (length > 80)
        {
            printf("%s\n", input);
        }
    }
    
}
