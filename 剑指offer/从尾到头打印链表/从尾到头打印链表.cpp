/**************************************
* @author dujiong
* @date 2017.2.13
* @version V0.1
**************************************/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//第一次遍历得到链表的长度，然后固定vector的size，从头遍历，将链表的值放到对应的位置上
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        if(head==nullptr){
            return ret;
        }
        int number=1;
        ListNode* temp = head;
        while(temp->next!=nullptr){
            number++;
            temp=temp->next;
        }
        ret.resize(number);
        int i=number-1;
        while(i>=0 && head!=nullptr){
            ret[i]=head->val;
            head=head->next;
            i--;
        }
        return ret;
    }
};


//使用栈
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        if(head==nullptr){
            return ret;
        }
        stack<ListNode*> lStack;
        while(head!=nullptr){
            lStack.push(head);
            head=head->next;
        }
        while(!lStack.empty()){
            ret.push_back((lStack.top())->val);
            lStack.pop();
        }
        return ret;
    }
};