/*
 * Program that will remove the duplicate elements from the linked lists
 *
 * @Harsh_Garg, 1910990582, 30/08/2021
 * Assignement 6
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    //creating a dummy node
    struct ListNode* dummy = (struct ListNode*) malloc( sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    
    struct ListNode* ptr = dummy;
    
    //whether to take the current element or not 
    int take = 1;
    
    while(head->next != NULL)
    {
        if(head->val == head->next->val)
        {
            take = 0;
        }
        else if(take == 1)
        {
            ptr->next = head;
            ptr = ptr->next;
            take = 1;
        }
        else if(take == 0)
        {
            take = 1;
        }
        head = head->next;
    }
    
    if(take == 1)
    {
        ptr->next = head;
        ptr = ptr->next;
    }
    
    ptr->next = NULL;
    
    return dummy->next;
}
