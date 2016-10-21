题目描述:
编写一个方法，确定某字符串的所有排列组合。
给定一个string A和一个int n,代表字符串和其长度，请返回所有该字符串字符的排列，保证字符串长度小于等于11且字符串中字符均为大写英文字符，排列中的字符串按字典序从大到小排序。(不合并重复字符串)
测试样例：
"ABC"
返回：["CBA","CAB","BCA","BAC","ACB","ABC"]

题目解析:
首先想到的是使用STL函数next_permutation，后面发现有字符串中相同字符，next_permutation不能处理。
所以，使用递归的方法，依次让每个元素作为字符串的第一个字符，然后递归的对剩余串进行全排列。

题目地址:
http://www.nowcoder.com/practice/8380c8cf28954a188362206b1991b5d6?tpId=8&tqId=11038&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking