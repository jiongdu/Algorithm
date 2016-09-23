/**************************************
* @author dujiong
* @date 2016.9.23
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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<int> temp;
        vector<vector<int> > ret;
        if(root==NULL){
			return ret;
        }
        FindPathHelp(root, temp, ret, 0, expectNumber);
        return ret;
    }
    
    void FindPathHelp(TreeNode* root, vector<int>& temp, vector<vector<int> >& ret, int sum, int expectNumber){
        if(root==NULL){
            return;
        }
        sum += root->val;
        temp.push_back(root->val);
        if(sum == expectNumber && root->left==NULL && root->right==NULL){
            ret.push_back(temp);
        }
        
        FindPathHelp(root->left,temp,ret,sum,expectNumber);
        FindPathHelp(root->right,temp,ret,sum,expectNumber);
        temp.pop_back();
    }
};
