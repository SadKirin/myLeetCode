/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        
        ListNode* rear = nullptr;
        ListNode* p = nullptr;
        ListNode* pnext = nullptr;
        
        p = head;
        
        while(p != nullptr){
            pnext = p->next;
            p->next = rear;
            rear = p;
            p = pnext;
        }
        
        head = rear;
        return head;
    }
};