/*
 *leetcode 543
 */

int diameterOfBinaryTree(TreeNode* root){
	int res = 0;
	maxDepth(root, res);
	return res;
}

int maxDepth(TreeNode* node, int& res){
	if(!node) return 0;
	int left = maxDepth(node->left, res);
	int right = maxDepth(node->right, res);
	res = max(res, left+right);
	return max(left, right)+1;
}