题目描述:
有一棵无穷大的满二叉树，其结点按根结点一层一层地从左往右依次编号，根结点编号为1。现在有两个结点a，b。请设计一个算法，求出a和b点的最近公共祖先的编号。
给定两个int a,b。为给定结点的编号。请返回a和b的最近公共祖先的编号。注意这里结点本身也可认为是其祖先。
测试样例：
2，3
返回：1

题目解析:
根据满二叉树的子节点与父节点之间的关系为root=child/2，所以，让a和b中间较大的数除以2，循环直到a == b。

题目地址:
http://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&tqId=11017&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking