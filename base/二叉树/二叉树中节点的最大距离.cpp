int FindMaxLen(TreeNode* root){
	if(root==nullptr) return 0;
	else if(root->left==nullptr && root->right==nullptr){
		return 0;
	}
	int dis=std::max(maxDepth(root->left)+maxDepth(root->right), FindMaxLen(root->left), FindMaxLen(root->right));
	if(maxDis<dis) maxDis=dis;
	return maxDis;
}

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