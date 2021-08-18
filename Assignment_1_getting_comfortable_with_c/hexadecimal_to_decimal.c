/*
 * Program to convert a hexadecimal string to a decimal number
 *
 * Compilation: gcc -o hexadecimal_to_decimal hexadecimal_to_decimal.c
 * Execution: ./hexadecimal_to_decimal
 * @Harsh_Garg,1910990582,07/08/2021
 * Assignement 1
 */

#include<stdio.h>
#include<string.h>

/*
 * Function which will take a hexadecimal string and return its decimal representation
 *
 * Parameters:
 * 1.an hexadecimal string
 */
int htoi(char* str)
{
    int len = strlen(str);
    
    int ans = 0;
    int p = 1;

    for(int i = len - 1; i >= 2 ; i--)
    {
        int current_digit;
        if(str[i] == 'a' || str[i] == 'A')
        {
            current_digit = 10;
        }
        else if(str[i] == 'b' || str[i] == 'B')
        {
            current_digit = 11;
        }
        else if(str[i] == 'c' || str[i] == 'C')
        {
            current_digit = 12;
        }
        else if(str[i] == 'd' || str[i] == 'D')
        {
            current_digit = 13;
        }
        else if(str[i] == 'e' || str[i] == 'E')
        {
            current_digit = 14;
        }
        else if(str[i] == 'f' || str[i] == 'F')
        {
            current_digit = 15;
        }
        else
        {
            current_digit = str[i] - '0';
        }
        
        ans += p * current_digit;
       
        p *= 16;
    }

    return ans;
}            
int main()
{
    char str[50];
    
    printf("Enter the String:");
    scanf("%s",str);
    
    int number = htoi(str);

    printf("%d", number);
    return 0;
}

 
