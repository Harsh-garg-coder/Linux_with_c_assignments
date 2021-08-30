/*
 * Program that will merge two sorted linked list
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


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* dummy = (struct ListNode*) malloc( sizeof(struct ListNode));
    dummy->val = -1;
    dummy->next = NULL;
    struct ListNode* ptr = dummy;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->val < l2->val)
        {
            ptr->next = l1;
            l1 = l1->next;
            ptr = ptr->next;
        }
        else
        {
            ptr->next = l2;
            l2 = l2->next;
            ptr = ptr->next;
        }
    }
    
    if(l1 != NULL)
    {
        ptr->next = l1;
    }
    
    if(l2 != NULL)
    {
        ptr->next = l2;
    }
    
    return dummy->next;
}
