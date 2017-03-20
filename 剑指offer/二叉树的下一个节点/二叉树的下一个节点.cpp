/**************************************
* @author dujiong
* @date 2017.3.20
* @version V0.1
**************************************/

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr){
            return nullptr;
        }
        TreeLinkNode* temp = pNode;
        if(temp->right!=nullptr){
            TreeLinkNode* right = pNode->right;
            while(right->left!=nullptr){
                right=right->left;
            }
            return right;
        }
        if(temp->next!=nullptr){
			TreeLinkNode* current=temp;
            TreeLinkNode* parent = temp->next;
            while(parent!=nullptr && current==parent->right){
                current=parent;
                parent=parent->next;
            }
            return parent;
        }
        return nullptr;
    }
};