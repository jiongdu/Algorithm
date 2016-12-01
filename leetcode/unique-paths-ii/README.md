题目描述:
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as1and0respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is2.
Note: m and n will be at most 100.

题目解析:
在unique-path的基础上添加了障碍。
仍然使用动态规划，将障碍位置的路径数量置为0。其余保持类似。

题目地址:
https://www.nowcoder.com/practice/3cdf08dd4e974260921b712f0a5c8752?tpId=46&tqId=29116&tPage=4&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking