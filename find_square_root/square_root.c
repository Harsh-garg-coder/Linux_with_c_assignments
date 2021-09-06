/**
 * program to find the square root of the given number till given precision
 *
 * @Harsh_Garg,1910990582,19/07/2021
 * Assignment 1
 */

#include<stdio.h> 

double find_square_root(int number,int precision);

int main() {
    
    //declaring the variables for number and precision
    int number = 0;
    int precision = 0;

    printf("Enter the number:");
    scanf("%d",&number);

    printf("Enter the precision:");
    scanf("%d",&precision);

    double ans = find_square_root(number,precision);

    printf("%f",ans);
}

double find_square_root(int number,int precision)
{
    //initialising the left and the right pointers for binary search
    int left = 0;
    int right = number;
    
    //initialising the variable for answer
    double ans = 0;


    while(left <= right) {
        int mid = left + (right - left) / 2;

        if (mid * mid == number)
        {
            ans = mid;
            break;
        }
        else if (mid * mid < number)
        {
            ans = mid;
            left = mid + 1;
        }
        else {
          right = mid-1;
        }
    }

    //calculating the fractional part
    double increment = 0.1;
    for(int i=0;i<precision;i++)
    {
       while(ans * ans <= number)
       {
           ans += increment;
       }

      ans -= increment;
      increment /= 10;
    }

    return ans;
