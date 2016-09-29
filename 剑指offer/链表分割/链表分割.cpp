/**************************************
* @author dujiong
* @date 2016.9.27
* @version V0.1
**************************************/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        if(pHead == NULL){
            return NULL;
        }
        ListNode* small = new ListNode(0);
        ListNode* large = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* largeHead = large;
        while(pHead){
            if(pHead->val < x){
                small->next = pHead;
                small = small->next;
            }else{
                large->next = pHead;
                large = large->next;
            }
            pHead = pHead->next;
        }
        large->next = NULL;
        small->next = largeHead->next;
        return smallHead->next;
    }
};