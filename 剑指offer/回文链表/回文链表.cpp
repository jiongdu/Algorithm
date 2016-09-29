/**************************************
* @author dujiong
* @date 2016.9.29
* @version V0.1
**************************************/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Palindrome {
public:
    bool isPalindrome(ListNode* pHead) {
        vector<int> value;
        ListNode* temp = pHead;
        while(temp!=NULL){
            value.push_back(temp->val);
            temp=temp->next;
        }
        pHead = ReverseList(pHead);
        int i=0;
        while(pHead!=NULL){
            if(pHead->val!=value[i++]){
                return false;
            }
            pHead=pHead->next;
        }
        return true;
    }
private:
    ListNode* ReverseList(ListNode* pHead){
        ListNode *pNext = NULL;
        ListNode *pPrev = NULL;
        while(pHead!=NULL){
            pNext = pHead->next;
            pHead->next = pPrev;
            pPrev = pHead;
            pHead = pNext;
        }
        return pPrev;
    }
};