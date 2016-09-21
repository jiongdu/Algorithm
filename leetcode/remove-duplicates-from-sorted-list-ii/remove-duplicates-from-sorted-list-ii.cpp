/**************************************
* @author dujiong
* @date 2016.9.21
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        p->next = head;
        while(head->next != NULL){
            if(head->val==head->next->val){
                while(head->next!=NULL && head->val == head->next->val){
                    ListNode* temp = head;
                    head = head->next;
                    delete temp;
                }
                if(head->next==NULL){
                    p->next = NULL;
                }else{
                    ListNode* temp = head;
                    p->next = head->next;
                    head = p-> next;
                    delete temp;
                }
            }else{
                head = head->next;
                p = p->next;
            }
        }
        return dummy->next;
    }
};
