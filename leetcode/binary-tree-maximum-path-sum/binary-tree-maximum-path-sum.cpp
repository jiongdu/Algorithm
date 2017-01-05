/**************************************
* @author dujiong
* @date 2017.1.5
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
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        dfs(root, ans);
        return ans;
    }
private:
    int dfs(TreeNode* root, int& ans){
        if(root==NULL) return 0;
        int l = std::max(0, dfs(root->left, ans));
        int r = std::max(0, dfs(root->right, ans));
        ans = std::max(ans, l+r+root->val);
        return std::max(l, r)+root->val;
    }
};