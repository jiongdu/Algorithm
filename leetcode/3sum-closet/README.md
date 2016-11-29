题目描述:
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

题目解析:
该题和3sum问题很类似，同样采取先固定一个数（遍历，下标从0到i-3），然后双指针找和与target距离最近的点。这里，需要保存和与target之间的差值，并做更新。

题目地址:
https://www.nowcoder.com/practice/291a866d7c904563876b373b0b157dde?tpId=46&tqId=29162&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking