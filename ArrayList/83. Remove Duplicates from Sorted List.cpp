/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        int val = head->val;
        ListNode* p = head;
        while(p && p->next){
            if(p->next->val != val){
                val = p->next->val;
                p = p->next;
            }
            else{
                ListNode* n = p->next->next;
                p->next = n;
            }
        }
        
        return head;
    }
};