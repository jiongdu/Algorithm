题目描述:
对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
给定一个字符串(不一定全为字母)A及它的长度n。请返回第一个重复出现的字符。保证字符串中有重复字符，字符串的长度小于等于500。

测试样例:
"qywyer23tdd",11

返回: y

题目解析:
这道题不难，使用关联容器map,用字符串中的字符和其对应的出现次数分别作为map的Key和Value。当某个字符次数达到2时，返回即为首个重复字符。

题目地址:
http://www.nowcoder.com/practice/dab59997905b4459a42587fece8a75f4?tpId=49&tqId=29279&rp=1&ru=/ta/2016test&qru=/ta/2016test/question-ranking
