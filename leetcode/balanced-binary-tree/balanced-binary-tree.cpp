/**************************************
* @author dujiong
* @date 2016.9.23
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
    bool isBalanced(TreeNode *root) {
        if(root==NULL){
            return true;
        }
        int leftDepth = depthOfBinaryTree(root->left);
        int rightDepth = depthOfBinaryTree(root->right);
        if(abs(leftDepth-rightDepth)<=1){
            if(isBalanced(root->left) && isBalanced(root->right)){
                return true;
            }
        }
        return false;
    }
private:
    int depthOfBinaryTree(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int ret = std::max(depthOfBinaryTree(root->left),depthOfBinaryTree(root->right));
        return ret+1;
    }
};