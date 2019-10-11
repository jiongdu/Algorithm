/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
//层次遍历的过程中来修改指针
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
        int levelNum = 1;
        int tempNum;
        while(!q.empty()) {
            tempNum = levelNum;
            levelNum = 0;
            for (int i = 0; i < tempNum; i++) {
                Node* node = q.front();
                q.pop();
                if(i != tempNum-1 && q.front() != nullptr) {
                    node->next = q.front();     //key
                }
                if (node->left != nullptr) {
                    q.push(node->left);
                    levelNum++;
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                    levelNum++;    
                }
            }
        }
        return root;
    }
};

//更巧妙的方法，不用额外的存储空间
void connect(TreeLinkNode *root) {
    if (root == NULL) return;
    TreeLinkNode *pre = root;
    TreeLinkNode *cur = NULL;
    while(pre->left) {
        cur = pre;
        while(cur) {        //一层一层地向右，太妙了，指针变换
            cur->left->next = cur->right;
            if(cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        pre = pre->left;
    }
}