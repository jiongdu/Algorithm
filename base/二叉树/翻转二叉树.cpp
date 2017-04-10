void invertBinaryTree(TreeNode* root){
	if(root==nullptr){
		return;
	}
	std::swap(root->left, root->right);
	invertBinaryTree(root->left);
	invertBinaryTree(root->right);
}