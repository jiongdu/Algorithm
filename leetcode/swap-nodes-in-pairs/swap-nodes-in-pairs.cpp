/**************************************
* @author dujiong
* @date 2016.9.22
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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while(p->next != NULL && head->next != NULL){
            p->next = head->next;
            head->next = p->next->next;
            p->next->next = head;
            
            p = p->next->next;
            head = head->next;
        }
        return dummy->next;
    }
};