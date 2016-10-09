题目描述:
实现一个函数，检查二叉树是否平衡，平衡的定义如下，对于树中的任意一个结点，其两颗子树的高度差不超过1。
给定指向树根结点的指针TreeNode* root，请返回一个bool，代表这棵树是否平衡。

题目解析:
递归的思想，每个节点的左右子树的最大深度之差不超过1，便是满足条件的平衡树。

题目地址:
http://www.nowcoder.com/practice/b6bbed48cd864cf09a34a6ca14a3976f?tpId=8&tqId=11011&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking