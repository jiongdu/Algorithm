题目描述:
约瑟夫问题是一个非常著名的趣题，即由n个人坐成一圈，按顺时针由1开始给他们编号。然后由第一个人开始报数，数到m的人出局。现在需要求的是最后一个出局的人的编号。
给定两个int n和m，代表游戏的人数。请返回最后一个出局的人的编号。保证n和m小于等于1000。
测试样例：
5 3
返回：4

题目解析:
链表实现，每隔m个删除一个元素，直到最后剩下一个，如果到达链表末尾，又重头开始。

题目地址:
http://www.nowcoder.com/practice/11b018d042444d4d9ca4914c7b84a968?tpId=8&tqId=11044&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking