/**************************************
* @author dujiong
* @date 2016.9.26
* @version V0.1
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root==NULL){
            return ret;
        }
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        TreeNode *temp = NULL;
        
        while(!treeStack.empty()){
            temp = treeStack.top();
            if(temp->left==NULL && temp->right==NULL){
                ret.push_back(temp->val);
                treeStack.pop();
            }else{
                if(temp->right){
                    treeStack.push(temp->right);
                    temp->right = NULL;
                }
                if(temp->left){
                    treeStack.push(temp->left);
                    temp->left = NULL;
                }
            }
        }
        return ret;
    }
};