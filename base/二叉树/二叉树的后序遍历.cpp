vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root==nullptr) return ret;
        stack<TreeNode*> treeStack;
		TreeNode* p = root;
		TreeNode* r = nullptr;
        while(p!=nullptr || !treeStack.empty()){
            if(p!=nullptr){
                treeStack.push(p);
                p=p->left;
            }else{
                p=treeStack.top();
				if(p->right!=nullptr && p->right!=r){
					p=p->right;
					treeStack.push(p);
					p=p->left;
				}else{
					p = treeStack.top();
					treeStack.pop();
					ret.push_back(p->val);
					r=p;
					p=nullptr;
				}
            }
        }
        return ret;
}
