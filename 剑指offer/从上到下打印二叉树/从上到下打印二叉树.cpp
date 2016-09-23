/**************************************
* @author dujiong
* @date 2016.9.23
* @version V0.1
**************************************/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode *root) {
		vector<int> ret;
        if(root==NULL){
            return ret;
        }
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        TreeNode* p = NULL;
        while(!treeQueue.empty()){
            p = treeQueue.front();
            treeQueue.pop();
            ret.push_back(p->val);
            
            if(p->left){
                treeQueue.push(p->left);
            }
            if(p->right){
                treeQueue.push(p->right);
            }
        }
        return ret;
    }
};
