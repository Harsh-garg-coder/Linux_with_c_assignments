/*
 * Program to reverse the linked list in range
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
 * Function that will reverse the linked list
 */
struct ListNode* reverseLinkedList(struct ListNode* head)
{
    struct ListNode* previous = NULL;
    struct ListNode* current = head;
    
    while(current != NULL)
    {
        struct ListNode* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    return previous;
}

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    if(left == right)
    {
        return head;
    }
    
    if(left == 1)
    {
        int count = 1;
        struct ListNode* ptr = head;
        while(count != right)
        {
            count++;
            ptr = ptr->next;
        }
        
        struct ListNode* temp = ptr->next;
        ptr->next = NULL;
        struct ListNode* newHead = reverseLinkedList(head);
        head->next = temp;
        return newHead;
    }
    else
    {
        int count = 1;
        struct ListNode* leftTail = head;
        while(count != left - 1)
        {
            count++;
            leftTail = leftTail->next;
        }
        
        struct ListNode* rightHead = leftTail;
        while(count != right)
        {
            count++;
            rightHead = rightHead->next;
        }
        
        struct ListNode* temp = rightHead->next;
        rightHead->next = NULL;
        rightHead = temp;
        
        struct ListNode* newHead = reverseLinkedList(leftTail->next);
        leftTail->next->next = rightHead;
        leftTail->next = newHead;
        
        return head;
    }
}
