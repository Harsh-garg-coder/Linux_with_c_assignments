/*
 * Program to find whether the given linked list is palindrome or not
 *
 * @Harsh_Garg, 1910990582, 30/08/2021
 * Assignment 6
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*
 * Function that will return the mid of the linked list using floyd's algorithm
 */
struct ListNode* findMid(struct ListNode* head)
{
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while(fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}

/*
 * Function that will reverse the linked list and retrun the head of the new linked list
 */
struct ListNode* reverseLinkedList(struct ListNode* head)
{
    struct ListNode* current = head;
    struct ListNode* previous = NULL;
    
    while(current != NULL)
    {
        struct ListNode* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    
    return previous;
}

/*
 * Function that will return true if the linked list is palindrome
 * and false if the linked list is not palindrome
 */
bool isPalindrome(struct ListNode* head){
    if(head == NULL || head->next == NULL)
    {
        return true;
    }
    struct ListNode* mid = findMid(head);
    
    struct ListNode* newHead = mid->next;
    mid->next = NULL;
    
    struct ListNode* newMid = reverseLinkedList(newHead);
    
    while(newMid != NULL)
    {
        if(head->val != newMid->val)
        {
            return false;
        }
        head = head->next;
        newMid = newMid->next;
    }
    
    return true;
}
