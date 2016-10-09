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

class Successor {
public:
    int findSucc(TreeNode* root, int p) {

        if(root==NULL){
            return -1;
        }
        int res=-1;
        inorder(root);
       	for(int i=0;i<ret.size()-1;i++){
            if(ret[i]==p){
				return ret[i+1];
            }
        }
        return res;
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