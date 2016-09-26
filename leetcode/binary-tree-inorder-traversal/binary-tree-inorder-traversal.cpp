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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        inorderTraversalHelp(root,ret);
        return ret;
    }
private:
    void inorderTraversalHelp(TreeNode* root, vector<int>& ret){
        if(root==NULL){
            return;
        }
        inorderTraversalHelp(root->left, ret);
        ret.push_back(root->val);
        inorderTraversalHelp(root->right, ret);
    }
};