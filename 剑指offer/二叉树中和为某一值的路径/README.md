﻿题目描述:
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

题目解析:
用前序遍历的方式访问到某一节点时，我们就把该节点添加到路径上，并累加该节点的值。如果该节点为叶节点并且路径中节点值的和刚好等于输入的整数，则当前的路径符合要求。如果当前节点不是叶节点，则继续访问它的子节点。当前节点访问结束后，递归函数将自动回到它的父节点。

题目地址:
http://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking