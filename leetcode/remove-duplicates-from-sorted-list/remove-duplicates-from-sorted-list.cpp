/**************************************
* @author dujiong
* @date 2016.9.17
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
        if(head==NULL){
            return NULL;
        }
        ListNode* pHead = head;
        while(head->next!=NULL){
            ListNode* next = head->next;
            if(head->val == next->val){
                head->next = next->next;
            }else{
                head = head->next;
            }
        }
        return pHead;
    }
};
