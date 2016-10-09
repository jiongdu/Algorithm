题目描述:
请设计一个算法，寻找二叉树中指定结点的下一个结点（即中序遍历的后继）。
给定树的根结点指针TreeNode* root和结点的值int p，请返回值为p的结点的后继结点的值。保证结点的值大于等于零小于等于100000且没有重复值，若不存在后继返回-1。

题目解析:
想到的方法是采用递归的方法中序遍历二叉树并存储结果，然后找节点值为p的值。

题目地址:
http://www.nowcoder.com/practice/60231d6931d543d4aadcb67851b21e4a?tpId=8&tqId=11016&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking