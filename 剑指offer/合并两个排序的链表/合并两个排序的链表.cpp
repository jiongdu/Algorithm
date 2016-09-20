/**************************************
* @author dujiong
* @date 2016.9.20
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL || pHead2==NULL){
            return (pHead1==NULL)?pHead2 : pHead1;
        }
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(pHead1!=NULL && pHead2!=NULL){
            if(pHead1->val <= pHead2->val){
                p->next = pHead1;
                pHead1 = pHead1->next;
            }else{
                p->next = pHead2;
                pHead2 = pHead2->next;
            }
            p = p->next;
        }
        p->next=((pHead1==NULL)?pHead2:pHead1);
        return dummy.next;
    }
};