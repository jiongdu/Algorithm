/**************************************
* @author dujiong
* @date 2016.9.26
* @version V0.1
**************************************/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
       vector<vector<int> > ret;
       levelOrderHelp(root, ret);
       return ret;
    }
private:
    void levelOrderHelp(TreeNode *root, vector<vector<int> >& ret){
        if(root==NULL){
            return;
        }
        queue<TreeNode*> que;
  		vector<int> level;
        que.push(root);
        
        int levelNum = 1;
        
        while(!que.empty()){
            int tempNum = levelNum;
            levelNum = 0;
            for(int i=0;i<tempNum;i++){
                root = que.front();
                int temp = root->val;
                que.pop();
                level.push_back(temp);
                if(root->left){
                	que.push(root->left);
                    levelNum++;
            	}
            	if(root->right){
                	que.push(root->right);
                    levelNum++;
            	}
            }
            ret.push_back(level);
            level.clear();         
        }
    }
};