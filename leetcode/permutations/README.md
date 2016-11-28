题目描述:
Given a collection of numbers, return all possible permutations.
For example,
[1,2,3]have the following permutations:
[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2], and[3,2,1].

题目解析:
首先想到的方法是使用STL的next_permutation算法，很简单。
然后尝试使用原始方法实现。从数组中选出每一个元素，作为排列的第一个元素，然后对剩余的元素进行全排列，如此递归处理，从而得到所有元素的全排列。

题目地址:
https://www.nowcoder.com/practice/4bcf3081067a4d028f95acee3ddcd2b1?tpId=46&tqId=29133&tPage=3&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking