题目描述:
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e.,0 1 2 4 5 6 7might become4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.

题目解析:
关键在于 整个旋转分组分为两部分之后，一定至少有一部分有序。
因此，仍可以使用二分查找。

题目地址:
http://www.nowcoder.com/practice/7cd13986c79d4d3a8d928d490db5d707?tpId=46&tqId=29146&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking