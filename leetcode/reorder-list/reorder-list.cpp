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
class Solution {
public:
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while(q && q->next){
            p = p->next;
            q = q->next->next;
        }
        ListNode *right = p->next;
       	p->next = NULL;
        ListNode *res = head;
        right = reverse(right);
        while(right!=NULL){
            ListNode* temp = res->next;
            res->next = right;
            ListNode* tempRight = right->next;
            right->next = temp;
            res = res->next->next;
            right = tempRight;
        }
    }
private:
    ListNode* reverse(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        ListNode* pNext = NULL;
        ListNode* pPrev = NULL;
        while(head!=NULL){
            pNext = head->next;
            head->next = pPrev;
            pPrev = head;
            head = pNext;
        }
        return pPrev;
    }
};	