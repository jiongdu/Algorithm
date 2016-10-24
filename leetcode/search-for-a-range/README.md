题目描述:
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return[-1, -1].
For example,
Given[5, 7, 7, 8, 8, 10]and target value 8,
return[3, 4].

题目解析:
要求O(log n)的复杂度，必然想到使用二分查找，找到target后，再分别向前和向后搜索。

题目地址:
http://www.nowcoder.com/practice/e302d06bcdac4171b9768fd354922880?tpId=46&tqId=29145&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking