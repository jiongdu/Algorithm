题目描述:
Implement regular expression matching with support for'.'and'*'.
'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true

题目解析:
很难的一道题，参考了别人的解法https://simpleandstupid.com/2014/10/14/regular-expression-matching-leetcode-%E8%A7%A3%E9%A2%98%E7%AC%94%E8%AE%B0/    
分成两种情况：
（1）p的第二个字符不是'*'，比较简单；
（2）p的第二个字符时'*'，这种情况复杂很多。

题目地址:
https://www.nowcoder.com/practice/d2ccc8cad7234aa5aa68c42471913b86?tpId=46&tqId=29168&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking