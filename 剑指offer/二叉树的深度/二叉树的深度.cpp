/**************************************
* @author dujiong
* @date 2017.2.17
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
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
    	if(pRoot==nullptr){
            return 0;
        }
        int number=1;
        return number+std::max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
    }
};