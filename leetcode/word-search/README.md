题目描述:
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
For example,
Given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word ="ABCCED", -> returnstrue,
word ="SEE", -> returnstrue,
word ="ABCB", -> returnsfalse.

题目解析:
二维数组的深度优先搜索，须好好掌握。

题目地址https://www.nowcoder.com/practice/14bcbcb7ae3c40c9bdbc5a0861361c29?tpId=46&tqId=29099&tPage=6&rp=6&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking