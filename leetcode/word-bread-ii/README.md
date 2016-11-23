题目描述:
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.
Return all such possible sentences.
For example, given
s ="catsanddog",
dict =["cat", "cats", "and", "sand", "dog"].
A solution is["cats and dog", "cat sand dog"].

题目解析:
在word-break的基础上加深了，除了需要得出位置，还要能切分出字符串。使用递归解决。
真的很好，有难度

题目地址:
http://www.nowcoder.com/practice/bd73f6b52fdc421d91b14f9c909f9104?rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking