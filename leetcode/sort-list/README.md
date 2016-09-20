题目描述:
Sort a linked list in O(n log n) time using constant space complexity.

题目解析:
要求O(nlogn)的复杂度，所以，选择使用归并排序，这里学习了用“快、慢”指针来找链表中间点的做法。然后，分别对左右两边进行排序，最后再merge。

题目地址:
http://www.nowcoder.com/practice/d75c232a0405427098a8d1627930bea6?tpId=46&tqId=29033&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking