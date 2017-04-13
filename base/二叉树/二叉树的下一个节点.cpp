TreeNode* GetNext(TreeNode* pNode){
	if(pNode==nullptr){
		return nullptr;
	}
	TreeNode* next = nullptr;
	if(pNode->pRight!=nullptr){
		TreeNode* right = pNode->pRight;
		while(right->pLeft!=nullptr){
			right=right->pLeft;
		}
		next=right;
	}else if(pNode->next!=nullptr){
		TreeNode* current = pNode;
		TreeNode* parent = pNode->pParent;
		while(parent!=nullptr && current==parent->pRight){		//直到找到一个是它父节点的左子节点的结点
			current=parent;
			parent=parent->pParent;
		}
		next=parent;
	}
	return next;
}