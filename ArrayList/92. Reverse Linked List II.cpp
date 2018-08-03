/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode HEAD(-1);
        HEAD.next = head;
        ListNode* prev = &HEAD;
        for(int i = 0; i < m - 1; i++){
            prev = prev->next;
        }
        ListNode* const head2 = prev;//待翻转链表的新头部
        prev = head2->next;//翻转后将成为最后一个点。不停用尾插法插入它之后的节点，插入完成后，该点自然成为最后一个节点。
        ListNode* cur = prev->next;
        for(int i = m; i < n; ++i){//保证cur是prev的下一个节点
            prev->next = cur->next;
            cur->next = head2->next;
            head2->next = cur;
            cur = prev->next;
        }
        
        return HEAD.next;
    }
};