/**************************************
* @author dujiong
* @date 2016.10.25
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
    ListNode *insertionSortList(ListNode *head) {
       	ListNode* dummy = new ListNode(INT_MIN);
        ListNode* cur = head;
        ListNode* pre = dummy;
        while(cur!=NULL){
            ListNode* next = cur->next;
            pre = dummy;
            while(pre->next != NULL && pre->next->val<cur->val){
                pre = pre->next;
            }
            cur->next = pre->next;
            pre->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};