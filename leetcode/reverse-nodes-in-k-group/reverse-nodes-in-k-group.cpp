/**************************************
* @author dujiong
* @date 2016.12.1
* @version V0.1
**************************************/

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || k==1){
            return head;
        }
       	auto node = head;
        for(int i=0;i<k;++i){
            if(!node) return head;
            node = node->next;
        }
		//递归实现
        auto new_head = ReverseList(head, node);	
        head->next = reverseKGroup(node, k);
        return new_head;
    }
private:
    ListNode* ReverseList(ListNode* pHead, ListNode* pEnd) {	//调用ReverseList(pHead, pEnd)实现[pHead, pEnd->prev](不包括pEnd)的反转
        if(pHead->next == pEnd){
            return NULL;
        }
        ListNode* pNext = NULL;
        ListNode* pPrev = NULL;
       	while(pHead != pEnd){
            pNext = pHead->next;
            pHead->next = pPrev;
            pPrev = pHead;
            pHead = pNext;
        }
        return pPrev;
    }
};
