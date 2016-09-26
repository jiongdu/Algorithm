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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0 || inorder.size()==0){
            return NULL;
        }
        return build(preorder, inorder, 0, preorder.size()-1, 0, preorder.size()-1);
        
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int l1, int r1, int l2, int r2)
    {
    	 if(l1>r1){
             return NULL;
         }   
        int gen = preorder[l1],i,cnt=0;
        for(i=l2;i<=r2&&inorder[i]!=gen;cnt++,i++);
        TreeNode* root = new TreeNode(gen);
        root->left = build(preorder, inorder, l1+1, l1+cnt, l2, i-1);
        root->right = build(preorder, inorder, l1+1+cnt, r1, i+1, r2);
        return root;
    }
    
};