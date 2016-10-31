题目描述:
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3

题目解析:
递归的对root的左右子树进行比较。因为是镜面对称，所以式root1->left与root2->right进行比较。

题目地址:
http://www.nowcoder.com/practice/1b0b7f371eae4204bc4a7570c84c2de1?tpId=46&tqId=29077&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking