题目描述:
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

题目解析:
首先每个child初始candy为1，然后进行两次扫描，第一次从左至右，遇到ratings比上一个child大的，candy数+1；接着第二次扫描，遇到ratings比上一个大，而candy又小于等于上一个的，candy数在上一个的基础上加1。

题目地址:
http://www.nowcoder.com/practice/74a62e876ec341de8ab5c8662e866aef?tpId=46&tqId=29045&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking