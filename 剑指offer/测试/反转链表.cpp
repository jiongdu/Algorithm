/**************************************
* @author dujiong
* @date 2016.9.17
* @version V0.1
**************************************/

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pNext = NULL;
        ListNode* pPrev = NULL;
       	while(pHead != NULL){
            pNext = pHead->next;
            pHead->next = pPrev;
            pPrev = pHead;
            pHead = pNext;
        }
        return pPrev;
    }
};
