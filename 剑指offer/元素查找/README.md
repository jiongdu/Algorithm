题目描述:
有一个排过序的数组，包含n个整数，但是这个数组向左进行了一定长度的移位，例如，原数组为[1,2,3,4,5,6]，向左移位5个位置即变成了[6,1,2,3,4,5],现在对于移位后的数组，需要查找某个元素的位置。请设计一个复杂度为log级别的算法完成这个任务。
给定一个int数组A，为移位后的数组，同时给定数组大小n和需要查找的元素的值x，请返回x的位置(位置从零开始)。保证数组中元素互异。
测试样例：
[6,1,2,3,4,5],6,6
返回：0

题目解析:
二分查找的变形，当A[mid]<x时，如果是传统二分则x应在mid和high之间，但是现在mid和high可能有两端有序序列，所以再加一层判断，当x>A[high]>A[mid]时，说明右边序列单调，但x比最大值还大，所以，x在左边。
依次，同理。

题目地址:
http://www.nowcoder.com/practice/72ff6503455c4a008675e79247ef2a3a?tpId=8&tqId=11047&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking