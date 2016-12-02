题目描述:

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

题目解析:
有些难度，使用回溯法，比如题中示例n=4,k=2；即从1、2、3、4中选两个数字组合，可以按以下思路进行，先选择1，那么只需要再选择一个数字，这时候k=1了（因为只需要选择一个数字了）。  每次选择一个加入我们的一维数组中，下一个只要再选择k-1个数字。 当k=0时，就将一维数组放入结果需要的二维数组中。
注意递归调用后，需要回溯，不然一维数组中会存放很多数。

题目地址:
https://www.nowcoder.com/practice/4d0a110416d84c7f9454d0da53ab2da1?tpId=46&tqId=29101&tPage=4&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking