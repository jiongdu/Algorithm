题目描述:
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

题目解析:
最简单的动态规划，转移方程：dp[n]=dp[n-1]+dp[n-2]

题目地址:
http://www.nowcoder.com/practice/d679cfa563974385a3bef8cd854c73db?tpId=46&tqId=29108&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking