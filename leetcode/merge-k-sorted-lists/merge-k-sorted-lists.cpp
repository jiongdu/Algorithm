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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n=lists.size();
        if(n==0){
            return NULL;
        }
        ListNode *res = lists[0];
        for(int i=1;i<n;i++){
            res=mergeTwoLists(res,lists[i]);
        }
        return res;
    }
    
private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL){
            return (l1==NULL)?l2 : l1;
        }
        ListNode dummy(0);
        ListNode* p = &dummy;
        while(l1!=NULL && l2!=NULL){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next=((l1==NULL)?l2:l1);
        return dummy.next;
    }
};