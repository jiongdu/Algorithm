/**************************************
* @author dujiong
* @date 2016.11.29
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        ListNode* prev = new ListNode(-1);
        ListNode* first = head;
        ListNode* last = head;
        ListNode* Next = last->next;
        prev->next = first;
        for(int i=0;i<m-1;i++){
            prev = prev->next;
			first = first->next;
        }
        for(int j=0;j<n-1;j++){
            last = last->next;
            Next = Next->next;
        }
        ListNode* temp = ReverseList(first, last->next);
        if(temp==NULL){
            return head;
        }else if(m==1){
            first->next = Next;
            return temp;
        }else{
            prev->next = temp;
            first->next = Next;
            return head;
        }
        return head;
    }
    
private:
    ListNode* ReverseList(ListNode* pHead, ListNode* pEnd) {
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