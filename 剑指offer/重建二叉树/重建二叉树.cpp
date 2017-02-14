/**************************************
* @author dujiong
* @date 2017.2.14
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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		if(pre.size()==0 || vin.size()==0) return nullptr;
        int length1 = pre.size();
        int length2 = vin.size();
        if(length1!=length2) return nullptr;
        return ConstructBinaryTree(&pre[0], &pre[length1-1], &vin[0], &vin[length2-1]);
    }
    
    TreeNode* ConstructBinaryTree(int* startPreorder, int* endPreorder, 
                                  int* startInorder, int* endInorder){
        int rootValue = startPreorder[0];
        TreeNode* root = new TreeNode(rootValue);
        
        if(startPreorder == endPreorder){
            if(startInorder==endInorder && *startPreorder==*startInorder){
                return root;
            }else{
                return nullptr;
            }
        }
        
        int* rootInorder = startInorder;
        while(rootInorder<=endInorder && *rootInorder!=rootValue){
            ++rootInorder;
        }
        if(rootInorder==endInorder && *rootInorder!=rootValue){
            return nullptr;
        }
        
        int leftLength=rootInorder-startInorder;
        int* leftPreorderEnd = startPreorder+leftLength;
        if(leftLength>0){
            root->left = ConstructBinaryTree(startPreorder+1, leftPreorderEnd, startInorder, rootInorder-1);
        }
        if(leftLength<endPreorder-startPreorder){
            root->right = ConstructBinaryTree(leftPreorderEnd+1, endPreorder, rootInorder+1, endInorder);
        }
        return root;
    }
};