题目描述:
假定我们都知道非常高效的算法来检查一个单词是否为其他字符串的子串。请将这个算法编写成一个函数，给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次检查子串的函数。
给定两个字符串s1,s2,请返回bool值代表s2是否由s1旋转而成。字符串中字符为英文字母和空格，区分大小写，字符串长度小于等于1000。

测试样例：
"Hello world","worldhello "

返回：false

"waterbottle","erbottlewat"
返回：true

题目解析:
很简单，在s1中找到和s2首字符相同的字符的位置，然后组合成新串看是否和s2相等。

题目地址:
http://www.nowcoder.com/practice/bc12808a2b0f445c96a64406d5513e96?tpId=8&tqId=11001&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking