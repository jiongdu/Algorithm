/**************************************
* @author dujiong
* @date 2016.10.9
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

class Checker {
public:
    bool checkBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        inorder(root);
        for(int i=0;i<ret.size()-1;++i){
			if(ret[i]>=ret[i+1]){
                return false;
            }
        }
        return true;
    }
    
    void inorder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(root->left);
        ret.push_back(root->val);
        inorder(root->right);
    }
	
private:
    vector<int> ret;
};