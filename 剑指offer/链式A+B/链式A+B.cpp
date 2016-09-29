/**************************************
* @author dujiong
* @date 2016.9.29
* @version V0.1
**************************************/

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Plus {
public:
    ListNode* plusAB(ListNode* a, ListNode* b) {
		if(a==NULL || b==NULL){
            return a==NULL ? b : a;
        }
      	ListNode* ret = new ListNode(0);
        ListNode* res = ret;
        int carry = 0;
        while(a!=NULL && b!=NULL){
            int temp = a->val + b->val + carry;
            carry = temp/10;
            temp = temp % 10;
            ret->next = new ListNode(temp);
            ret = ret->next;
 
            a=a->next;
            b=b->next;	
        }
        if(a!=NULL || b!=NULL){
            ListNode* left = (a==NULL?b:a);
        	while(left!=NULL){
            	int temp2 = left->val+carry;
            	carry = temp2/10;
            	temp2 = temp2 % 10;
            	ret->next = new ListNode(temp2);
            	ret = ret->next;
            	left = left->next;
        	}
        }
  		if(carry>0){
			ret->next = new ListNode(carry);
        }
        return res->next;
   	}
    

};