题目描述:
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
For example:
Given the below binary tree andsum = 22,
  	      5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1


题目解析:
递归操作，没向下遍历一层，就用sum减掉该子树root节点的val值。

题目地址:
http://www.nowcoder.com/practice/508378c0823c423baa723ce448cbfd0c?tpId=46&tqId=29067&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking