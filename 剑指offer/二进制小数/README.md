题目描述:
有一个介于0和1之间的实数，类型为double，返回它的二进制表示。如果该数字无法精确地用32位以内的二进制表示，返回“Error”。
给定一个double num，表示0到1的实数，请返回一个string，代表该数的二进制表示或者“Error”。
测试样例：
0.625
返回：0.101

题目解析:
例如：num = 0.625
因为小数点后第一位表示的是0.5，第二位是0.25，第三位是0.125。。。。。。
如果num 大于等于 base = 0.5 则第一位则为1，num 减去0.5 否则为0。无论是不是为1，base都的除以2，以来判断第二位是不是为1，以此类推。

题目地址:
http://www.nowcoder.com/practice/743853af75fc4026939a682b86535f79?tpId=8&tqId=11020&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking