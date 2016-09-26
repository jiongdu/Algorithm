题目描述:
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree{3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

题目解析:
使用队列来存储中间遍历的节点，只是要注意保存每个层次节点的个数。

题目地址:
http://www.nowcoder.com/practice/04a5560e43e24e9db4595865dc9c63a3?tpId=46&tqId=29076&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking