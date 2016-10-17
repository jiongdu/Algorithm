/**************************************
* @author dujiong
* @date 2016.10.17
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

/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class TreeLevel {
public:
    ListNode* getTreeLevel(TreeNode* root, int dep) {
        // write code here
        if(root == NULL){
            return NULL;
        }
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        int index = 1;
        int num=1;
        while(!treeQueue.empty() && index<dep){
            int i=1;
            int k=1;
            while(i<=num){
                TreeNode* temp = treeQueue.front();
                treeQueue.pop();
                if(temp->left!=NULL){
                    treeQueue.push(temp->left);
                    k++;
                }
                if(temp->left!=NULL){
                    treeQueue.push(temp->right);
                    k++;
                }
                i++;
            }
            num = k-1;
            
            index++;
        }
        ListNode* ListRoot = new ListNode(-1);
        ListNode* ListNext = ListRoot;
        while(!treeQueue.empty()){
            TreeNode* tempTreeNode = treeQueue.front();
            treeQueue.pop();
            ListNode* tempListNode = new ListNode(tempTreeNode->val);
            ListNext->next = tempListNode;
            ListNext = ListNext->next;
        }
        return ListRoot->next;
    }
};