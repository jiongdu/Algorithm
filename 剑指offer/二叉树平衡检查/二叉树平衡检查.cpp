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

class Balance {
public:
    bool isBalance(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int leftDepth = getLength(root->left);
        int rightDepth = getLength(root->right);
        if(abs(leftDepth-rightDepth)<=1 && isBalance(root->left) && isBalance(root->right)){
                return true;
        }
        return false;
    }
private:
    int getLength(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int index=1;
        index+=std::max(getLength(root->left),getLength(root->right));
        return index;
    }
};