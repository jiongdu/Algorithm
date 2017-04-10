vector<vector<int>> levelOrder(TreeNode *root){
	vector<vector<int> > ret;
	if(root==nullptr){
		return ret;
	}
	queue<TreeNode*> q;
	q.push(root);
	int levelNum=1;
	int tempNum;
	vector<int> temp;
	while(!q.empty()){
		tempNum=levelNum;
		levelNum=0;
		for(int i=0;i<tempNum;++i){
			TreeNode* tmp = q.front();
			q.pop();
			temp.push_back(tmp->val);
			if(tmp->left!=nullptr){
				q.push(tmp->left);
				levelNum++;
			}
			if(tmp->right!=nullptr){
				q.push(tmp->right);
				levelNum++;
			}
		}
		ret.push_back(temp);
		temp.clear();
	}
	return ret;
}