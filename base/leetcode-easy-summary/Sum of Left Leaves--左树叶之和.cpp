
/*
 * leetcode: 404
 * 递归的进一步应用
 */
 
 int sumOfLeftLeaves(TreeNode* root){
	 if(!root) return 0;
	 if(root->left && !root->left->left && !root->left->right) return root->left->val+sumOfLeftLeaves(root->right);
	 return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
 }