题目描述:
请编写一个方法，对一个字符串数组进行排序，将所有变位词合并，保留其字典序最小的一个串。这里的变位词指变换其字母顺序所构成的新的词或短语。例如"triangle"和"integral"就是变位词。
给定一个string的数组str和数组大小int n，请返回排序合并后的数组。保证字符串串长小于等于20，数组大小小于等于300。
测试样例：
["ab","ba","abc","cba"]
返回：["ab","abc"]

题目解析:
首先对字符串数组进行排序，遍历排序后的序列，若变位词（将每个字符串进行排序）没出现过，则将其加入到set和返回数组。

题目地址:
http://www.nowcoder.com/practice/764edc8f2a6147429a098f422753853b?tpId=8&tqId=11046&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking