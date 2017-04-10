vector<vector<int> > FindPath(TreeNode* root, int expectNumber){
	vector<vector<int> > ret;
	vector<int> temp;
	if(root==nullprtr){
		return ret;
	}
	int sum = 0;
	FindPathHelp(root, ret, temp, sum, expectNumber);
	return ret;
}

void FindPathHelp(TreeNode* root, vector<vector<int> >& ret, vector<int>& temp, int sum, int expectNumber){
	if(root==nullptr){
		return;
	}
	sum += root->val;
	temp.push_back(root->val);
	if(sum == expectNumber && root->left != nullptr && root->right != nullptr){
		ret.push_back(temp);
	}
	FindPathHelp(root->left, ret, temp, sum, expectNumber);
	FindPathHelp(root->right, ret, temp, sum, expectNumber);
	temp.pop_back();
}