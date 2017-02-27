/**************************************
* @author dujiong
* @date 2017.2.27
* @version V0.1
**************************************/

/*
 * 水塘抽样算法描述：
 *
 *     从S中抽取首K项放入[水塘]中
 *     对于每一个S[i]项(j>=k):
 *         随机产生一个范围0到j的整数r
 *         若r<k  则把水塘中第r项换成s[j]项
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head_=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int res=head_->val;
        int k=1;
        int j=2;        //j
        ListNode* temp = head_->next;
        while(temp){
            int r=rand()%j;
            if(r<k)res=temp->val;
            ++j;
            temp=temp->next;
        }
        return res;
    }
private:
    ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */