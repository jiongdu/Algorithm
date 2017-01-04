/**************************************
* @author dujiong
* @date 2017.1.4
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
    int sumNumbers(TreeNode *root) {
        return func(root, 0);
    }
private:
    int func(TreeNode *root, int sum){
        if(root==NULL) return 0;
        sum = sum*10+root->val;
        if(root->left==NULL && root->right==NULL) return sum;
        return func(root->left, sum) + func(root->right, sum);
    }
};