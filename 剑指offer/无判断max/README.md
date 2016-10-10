题目描述:
请编写一个方法，找出两个数字中最大的那个。条件是不得使用if-else等比较和判断运算符。
给定两个int a和b，请返回较大的一个数。若两数相同则返回任意一个。
测试样例：
1，2
返回：2

题目解析:
若a>b,b=a-b>0，则b>>31为0,与b&后结果为0
若a<b,b=a-b<0，则b>>31为11111111...111，与b&后仍结果为b（a-b）

题目地址:
http://www.nowcoder.com/practice/b0a82250677a4fabb0bc41053fa05013?tpId=8&tqId=11056&rp=4&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking