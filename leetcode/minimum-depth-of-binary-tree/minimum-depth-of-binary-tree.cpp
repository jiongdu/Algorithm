/**************************************
* @author dujiong
* @date 2016.9.20
* @version V0.1
**************************************/

class Solution {
public:
    int run(TreeNode *root) {
        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            return 1;
        }else if(root->left==NULL){
			return run(root->right)+1;
        }else if(root->right==NULL){
			return run(root->left)+1;
        }
        int ret = 1;
        ret += std::min(run(root->left),run(root->right));
        return ret;
    }
};
