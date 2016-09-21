题目描述:
Given a binary tree, return the preorder traversal of its nodes' values.
For example:
Given binary tree{1,#,2,3},
   1
    \
     2
    /
   3

return[1,2,3].

题目解析:
采用了两种方法，第一种是最常用的递归的方式，第二种是使用栈，因为前序顺序为 根，左，右，所以，循环让右儿子先入栈。

题目地址:
http://www.nowcoder.com/practice/501fb3ca49bb4474bf5fa87274e884b4?tpId=46&tqId=29036&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking