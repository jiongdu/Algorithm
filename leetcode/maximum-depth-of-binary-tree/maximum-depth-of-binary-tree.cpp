/**************************************
* @author dujiong
* @date 2016.9.17
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
    int maxDepth(TreeNode *root) {
        if(root == NULL){
        	return 0;
        }
        int ret=1;
        if(root->left!=NULL || root->right!=NULL){
            ret+=std::max(maxDepth(root->left),maxDepth(root->right));
        }
        return ret;
    }
};
