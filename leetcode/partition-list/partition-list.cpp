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
    ListNode *partition(ListNode *head, int x) {
        ListNode *dummy1 = new ListNode(INT_MIN);
        ListNode *list1 = dummy1;
        ListNode *dummy2 = new ListNode(INT_MAX);
        ListNode *list2 = dummy2;
        while(head!=NULL){
            ListNode* next = head->next;
            if(head->val<x){
                list1->next = head;
                list1 = list1->next;
            }else{
                list2->next = head;
                list2 = list2->next;
            }
            head = next;
        }
        list1->next = dummy2->next;
        list2->next = NULL;
        return dummy1->next;
    }
};