/**************************************
* @author dujiong
* @date 2016.9.21
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
      	preorder(root,res);
        return res;
    }
private:
     void preorder(TreeNode* root, vector<int>& vec)
     {
         if(root==NULL){
             return;
         }
         vec.push_back(root->val);
         preorder(root->left,vec);
         preorder(root->right,vec);
     }
};