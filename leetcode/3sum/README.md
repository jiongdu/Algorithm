题目描述:
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)

题目解析:
将3sum问题转化为2sum，原问题等价于，对于下标为i:0-num.size()-3的数，在i+1到num.size()-1中找到两个和为-num[i]的数，在寻找的过程中，使用了双指针的思想，因此，总的复杂度为(n^2)，比全部遍历的O(n^3)好。

题目地址:
https://www.nowcoder.com/practice/345e2ed5f81d4017bbb8cc6055b0b711?tpId=46&tqId=29163&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking