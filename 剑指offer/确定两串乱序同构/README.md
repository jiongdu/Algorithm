题目描述:
给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。这里规定大小写为不同字符，且考虑字符串重点空格。
给定一个string stringA和一个string stringB，请返回一个bool，代表两串是否重新排列后可相同。保证两串的长度都小于等于5000。

题目解析:
这里给出了三种方法，时间复杂度分别是O(nlgn)，O(n)，O(n)。在需要存储字符的个数时，最好首先想到char a[256]，而不是map<char, int>。

题目地址:
http://www.nowcoder.com/practice/164929d4acd04de5b0ee2d93047b3b20?tpId=8&tqId=10996&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking