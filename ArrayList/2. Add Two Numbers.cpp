/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        int carry = 0; //进位
        ListNode *p = &head;
        //考虑位数不一样的情况
        for(ListNode* p1 = l1, *p2 = l2; p1 != nullptr || p2 != nullptr;
           p1 = p1 == nullptr ? nullptr : p1->next,
           p2 = p2 == nullptr ? nullptr : p2->next,
           p = p->next){
            int ai = p1 == nullptr ? 0 : p1->val;
            int bi = p2 == nullptr ? 0 : p2->val;
            int value = (ai+bi+carry) % 10;
            carry = (ai+bi+carry) / 10;
            p->next = new ListNode(value);
        }
        //加上最高位的进位
        if(carry > 0){
            p->next = new ListNode(carry);
        }
        return head.next;
    }
};