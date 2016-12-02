/**************************************
* @author dujiong
* @date 2016.12.2
* @version V0.1
**************************************/

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
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return head;
     	//第一步，在原链表的每个节点后面添加复制节点
        RandomListNode* nowNode = head;
        while(nowNode != NULL){
            RandomListNode* copyNode = new RandomListNode(nowNode->label);
            copyNode->next = nowNode->next;
            copyNode->random = nowNode->random;
            nowNode->next = copyNode;
            nowNode = nowNode->next->next;
        }
        //第二步，改变random的指向，使其指向复制后的节点
        nowNode = head;
        while(nowNode != NULL){
            if(nowNode->random != NULL){
                nowNode->next->random = nowNode->random->next;
            }
            nowNode = nowNode->next->next;
        }
        //第三步，拆分为两个链表，得到最后复制的链表
        RandomListNode* pHead = new RandomListNode(-1);
        pHead->next = head;
        RandomListNode* newList = pHead;
        
        nowNode = head;
        while(nowNode != NULL){
            pHead->next = nowNode->next;
            nowNode->next = pHead->next->next;
            pHead = pHead->next;
            nowNode = nowNode->next;
        }
        return newList->next;
    }
};
