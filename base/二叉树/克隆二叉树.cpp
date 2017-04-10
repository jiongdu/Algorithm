TreeNode* cloneTree(TreeNode *root){
	if(root==nullptr) return root;
	TreeNode* ret = new TreeNode(root->val);
	ret->left = cloneTree(root->left);
	ret->right = cloneTree(root->right);
	return ret;
}