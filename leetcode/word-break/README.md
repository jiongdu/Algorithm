题目描述:
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
For example, given
s ="leetcode",
dict =["leet", "code"].
Return true because"leetcode"can be segmented as"leet code".

题目解析:
动态规划，想象成中间插隔板，看是否可以分割的每一部分都可以在dict中找到。

题目地址:
http://www.nowcoder.com/practice/5f3b7bf611764c8ba7868f3ed40d6b2c?tpId=46&tqId=29041&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking