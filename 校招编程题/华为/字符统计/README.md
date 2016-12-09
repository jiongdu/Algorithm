题目描述:
对字符中的
各个英文字符（大小写分开统计），数字，空格进行统计，并按照统计个数由多到少输出,如果统计的个数相同，则按照ASII码由小到大排序输出 。如果有其他字符，则对这些字符不用进行统计。

输入描述：
输入一行以空格来分隔的句子

输出描述：
输出句子的逆序

输入例子：
aadddccddc

输出例子：
dca

题目解析:
用map存储字符和其出现的次数，但是由于map不是线性容器，所以在按题目要求排序时，先将map中的元素（pair）转移到vector中。

题目地址:
https://www.nowcoder.com/practice/c1f9561de1e240099bdb904765da9ad0?tpId=37&tqId=21325&tPage=3&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking