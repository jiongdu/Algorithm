题目描述:
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
For example,
Given n = 3, there are a total of 5 unique BST's.
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

题目解析:
二叉查找数可以任意取根，只要满足中序遍历有序的要求就可以。从处理子问题的角度来看，选取一个节点为根，就把节点分成左右子树，以这个节点为根的可行二叉树数量就是左右子树可行二叉树数量的乘积，所以总的数量是将以所有节点为根的可行结果累加起来。

题目地址:
https://www.nowcoder.com/practice/b2b6734cbc0b43088f6084785046b861?tpId=46&tqId=29083&tPage=3&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking