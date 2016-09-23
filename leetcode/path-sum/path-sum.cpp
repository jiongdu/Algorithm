/**************************************
* @author dujiong
* @date 2016.9.22
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
    bool hasPathSum(TreeNode *root, int sum) {
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val==sum;
        }
      
       	if(hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val)){
                return true;
        }
        
        return false;
    }
};