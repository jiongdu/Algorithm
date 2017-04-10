vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        if(root==nullptr) return ret;
        stack<TreeNode*> treeStack;
        while(root!=nullptr || !treeStack.empty()){
            if(root!=nullptr){
                treeStack.push(root);
                root=root->left;
            }else{
                root=treeStack.top();
                treeStack.pop();
                ret.push_back(root->val);   
                root=root->right;           //important
            }
        }
        return ret;
}
