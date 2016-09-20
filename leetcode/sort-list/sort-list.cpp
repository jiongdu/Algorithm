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
    ListNode *sortList(ListNode *head) {
        if(!head || !head->next) return head;
        ListNode* p=head;
        ListNode* q=head->next;
        
        while(q && q->next){	//快慢指针思路，慢指针来找到链表的中间节点
            p = p->next;
            q = q->next->next;
        }
        ListNode* right = sortList(p->next);
        p->next=NULL;
        ListNode* left = sortList(head);
        return merge(left, right);
     }
 	 
private:
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(left && right){
            if(left->val < right->val){
                p->next = left;
                left = left->next;
            }else{
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        if(left) p->next = left;
        if(right) p->next = right;
        return dummy.next;
    }
       
};