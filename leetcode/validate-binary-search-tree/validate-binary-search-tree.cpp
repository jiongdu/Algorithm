/**************************************
* @author dujiong
* @date 2016.10.31
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
    bool isValidBST(TreeNode *root) {
        if(root==NULL){
            return true;
        }
        getInorder(root);
        for(int i=0;i<inorder.size()-1;++i){
            if(inorder[i]>=inorder[i+1]){
                return false;
            }
        }
        return true;
    }
private:
    void getInorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        getInorder(root->left);
        inorder.push_back(root->val);
        getInorder(root->right);
    }
    vector<int> inorder;
};