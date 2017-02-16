/**************************************
* @author dujiong
* @date 2017.2.16
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr || pHead2==nullptr){
            return nullptr;
        }
        unsigned int len1 = GetLengthOfList(pHead1);
        unsigned int len2 = GetLengthOfList(pHead2);
        
        int lengthDiff = len1-len2;
        ListNode* pListHeadLong = pHead1;
        ListNode* pListHeadShort = pHead2;
        if(len2>len1){
            pListHeadLong = pHead2;
            pListHeadShort = pHead1;
            lengthDiff = len2-len1;
        }
        for(int i=0;i<lengthDiff;i++){
            pListHeadLong=pListHeadLong->next;
        }
        while(pListHeadLong!=nullptr && pListHeadShort!=nullptr){
            if(pListHeadLong==pListHeadShort){
                break;
            }else{
                pListHeadLong=pListHeadLong->next;
                pListHeadShort=pListHeadShort->next;
            }
        }
        return pListHeadLong;
    }
    
    unsigned int GetLengthOfList(ListNode* pHead){
        int len=0;
        while(pHead!=nullptr){
            len++;
            pHead=pHead->next;
        }
        return len;
    }
};