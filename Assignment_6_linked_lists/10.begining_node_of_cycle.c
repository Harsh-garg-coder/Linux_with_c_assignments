/*
 * Program that will return the node from where the cycle begins
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
 * Function that will return return NULL if the cycle is not present
 * and if the cycle is present return the node from where the cycle begins
 */
struct ListNode* isCyclePresent(struct Listnode* head)
{
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if(fast == slow)
        {
            return slow;
        }
    }
    
    return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* slow = isCyclePresent(head);
    
    if(slow == NULL)
    {
        return NULL;
    }
    else
    {
        struct ListNode* ptr = head;
        
        while(ptr != slow)
        {
            slow = slow->next;
            ptr = ptr->next;
        }
        
        return ptr;
    }
}
