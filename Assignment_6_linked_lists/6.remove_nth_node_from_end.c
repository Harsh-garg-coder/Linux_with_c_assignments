/*
 * Program to remove the nth element from the end of the linked list
 * @Harsh_Garg, 1910990582, 30/08/2021
 * Assignment 6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Function that will retrun the length of the linked list
 */
int findLength(struct ListNode* head)
{
    int count = 0;
    
    while(head != NULL)
    {
        head = head->next;
        count++;
    }
    
    return count;
}

/* 
 * Function that will remove the nth element from the end of the linked list 
 * and return the new head
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    int length = findLength(head);
    
    //if the element to be removed is the first element of the linked list
    if(length == n)
    {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else
    {
        struct ListNode* iterator = head;
        int count = 1;
        while(count != length - n)
        {
            iterator = iterator->next;
            count++;
        }
        struct ListNode* toBeDeleted = iterator->next;
        iterator->next = iterator->next->next;
        free(toBeDeleted);
        return head;
    }
}

