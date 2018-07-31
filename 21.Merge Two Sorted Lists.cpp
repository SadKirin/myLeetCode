/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr && l2 == nullptr)
            return nullptr;
        else if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;
        
        ListNode* p = nullptr;
        ListNode* Head = nullptr;
        
        if(l1->val <= l2->val){
            Head = l1;
            l1 = l1->next;
        }
        else{
            Head = l2;
            l2 = l2->next;
        }
        
        p = Head;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
                p = p->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
                p = p->next;
            }
        }
            
            if(l1 == nullptr){
                p->next = l2;
            }
            
            if(l2 == nullptr){
                p->next = l1;
            }
        return Head;
    }
};