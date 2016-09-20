/**************************************
* @author dujiong
* @date 2016.9.20
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL){
            return head;
        }
        //添加dummy节点可以很好的解决删除头结点的情况
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        while(fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = temp->next;
        delete temp;
        return dummy->next;
    }
};