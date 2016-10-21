题目描述:
Given an array of strings, return all groups of strings that are anagrams.
Note: All inputs will be in lower-case.

题目解析:
首先对字符串数组中的每个串排序，保证变形词具有相同的形式，然后使用map存储每个词的出现次数，如果大于等于1则为需要的变形词。

题目地址:
http://www.nowcoder.com/practice/e84e273b31e74427b2a977cbfe60eaf4?tpId=46&tqId=29130&rp=6&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking