/*
 * Program to implement Tower of Hanoi and printing the movement along with the count of the movements
 *
 * Compilation: gcc -o tower_of_hanoi tower_of_hanoi.c
 * Execution: ./tower_of_hanoi 
 * @Harsh_Garg,1910990582,06/08/2021
 * Assignement 5
 */

#include<stdio.h>

int no_of_movements;
int count;

/*
 * Function to print the movement and count of the moves required to solve 
 * tower of hanoi problem for given no. of disks.
 * 
 * Parameters:
 * 1. no of disks
 * 2. name of the tower on which disks are present initialy
 * 3. name of the tower on which we want to shift the disks
 * 4. name of the tower used for this process
 */
void tower_of_hanoi(int disks, char from, char to, char using)
{
    if(disks < 1)
    {
        return;
    }
     
    count++;

    tower_of_hanoi(disks - 1, from, using, to);
    no_of_movements++;
    printf("%c to %c\n", from, to);
    tower_of_hanoi(disks - 1, using, to, from);
    
    count--;

    if(count == 0)
    {
        printf("Total Movements Required: %d",no_of_movements);
    }
}   

int main()
{
    tower_of_hanoi(3,'A','C','B');
    return 0;
}

 
