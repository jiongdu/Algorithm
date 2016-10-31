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
    bool isSymmetric(TreeNode *root) {
        if(root==NULL){
            return true;
        }
        return isEqual(root->left, root->right);
    }
private:
	bool isEqual(TreeNode* root1, TreeNode* root2){
        if(root1==NULL && root2==NULL){
            return true;
        }
        if(root1==NULL || root2==NULL){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        return isEqual(root1->left, root2->right) && isEqual(root1->right, root2->left);
    }    	
};