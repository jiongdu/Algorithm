/**************************************
* @author dujiong
* @date 2017.2.13
* @version V0.1
**************************************/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//循环的方法
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot==nullptr){
            return;
        }
        stack<TreeNode*> treeStack;
        treeStack.push(pRoot);
        while(!treeStack.empty()){
            TreeNode* temp = treeStack.top();
            treeStack.pop();
            std::swap(temp->left, temp->right);
			//这里的左右顺序无妨
            if(temp->left!=nullptr){
                treeStack.push(temp->left);
            }
            if(temp->right!=nullptr){
                treeStack.push(temp->right);
            }
        }
    }
};

//递归的方法
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
        if(pRoot==nullptr){
            return;
        }
        if(pRoot->left!=nullptr || pRoot->right!=nullptr){
            std::swap(pRoot->left, pRoot->right);
        }
        if(pRoot->left!=nullptr){
            Mirror(pRoot->left);
        }
        if(pRoot->right!=nullptr){
            Mirror(pRoot->right);
        }
    }
};