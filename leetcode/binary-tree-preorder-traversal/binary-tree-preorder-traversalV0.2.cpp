/**************************************
* @author dujiong
* @date 2016.9.21
* @version V0.2
**************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
  		vector<int> res;
        stack<TreeNode*> treeStack;
        if(root==NULL){
            return res;
        }
        treeStack.push(root);
        while(!treeStack.empty()){
            TreeNode* cur = treeStack.top();
            treeStack.pop();
            res.push_back(cur->val);
            if(cur->right!=NULL){
                treeStack.push(cur->right);
            }
            if(cur->left!=NULL){
                treeStack.push(cur->left);
            }
        }
        return res;
    }
};