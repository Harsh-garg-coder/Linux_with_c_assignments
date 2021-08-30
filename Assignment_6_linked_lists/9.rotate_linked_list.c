/*
 * Program that will rotate the linked list
 * 
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
 * function that will return the length of the linked list
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

struct ListNode* rotateRight(struct ListNode* head, int k){
    
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    int len = findLength(head);
    
    k = k % len; 
    if(k == 0)
    {
        return head;
    }
    
    int count = 1;
    
    struct ListNode* ptr = head;
    while(count != len - k)
    {
        count++;
        ptr = ptr->next;
    }
    
    struct ListNode* newHead = ptr->next;
    ptr->next = NULL;
    struct ListNode* ptr2 = newHead;
    
    while(ptr2->next != NULL)
    {
        ptr2 = ptr2->next;
    }
    
    ptr2->next = head;
    
    return newHead;
}

