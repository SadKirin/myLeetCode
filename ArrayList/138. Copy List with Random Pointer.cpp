/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
*/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *pHead) {
        CloneNodes(pHead);
        ConnectSiblingNodes(pHead);
        return ReconnectNodes(pHead);
    }
    
private:
    void CloneNodes(RandomListNode* phead){
        RandomListNode* pNode = phead;
        while(pNode != nullptr){
            RandomListNode* pClone = new RandomListNode(0);
            pClone->label = pNode->label;
            pClone->next = pNode->next;
            pClone->random = nullptr;
            
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }
    
    void ConnectSiblingNodes(RandomListNode* phead){
        RandomListNode* pNode = phead;
        while(pNode != nullptr){
            RandomListNode* pClone = pNode->next;
            if(pNode->random != nullptr){
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }
    
    RandomListNode* ReconnectNodes(RandomListNode* phead){
        RandomListNode* pNode = phead;
        RandomListNode* pCloneHead = nullptr;
        RandomListNode* pCloneNode = nullptr;
        
        if(pNode != nullptr){//初始化
            pCloneNode = pCloneHead = pNode->next;
            pNode->next = pCloneHead->next;
            pNode = pNode->next;
        }
        
        while(pNode != nullptr){
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;
            
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        
        return pCloneHead;
    }
};