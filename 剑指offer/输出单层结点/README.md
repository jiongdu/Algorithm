题目描述:
对于一棵二叉树，请设计一个算法，创建含有某一深度上所有结点的链表。
给定二叉树的根结点指针TreeNode* root，以及链表上结点的深度，请返回一个链表ListNode，代表该深度上所有结点的值，请按树上从左往右的顺序链接，保证深度不超过树的高度，树上结点的值为非负整数且不超过100000。

题目解析:
DFS的思想，采用队列结构，逐层向下遍历，注意保存每层的节点数。

题目地址:
http://www.nowcoder.com/practice/cb6c883b123b44399377d0c71e6ba3ea?tpId=8&tqId=11014&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking