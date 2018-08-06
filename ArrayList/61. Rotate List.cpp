/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0){
            return head;
        }
        
        int len = 1;
        ListNode* p = head;
        while(p->next){//求链表长度
            p = p->next;
            ++len;
        }
        
        k = len - k % len;//取余
        
        p->next = head;//连成环
        for(int i = 0; i < k; ++i){
            p = p->next;
        }
        
        head = p->next;//断开环
        p->next = nullptr;
        return head;
    }
};