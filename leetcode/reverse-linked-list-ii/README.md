题目描述:
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given1->2->3->4->5->NULL, m = 2 and n = 4,
return1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

题目解析:
使用了之前翻转链表的方法，找到需要翻转的起点和终点，然后对该部分进行翻转，然后做指针操作，将各部分连接起来。

题目地址:
https://www.nowcoder.com/practice/b58434e200a648c589ca2063f1faf58c?tpId=46&tqId=29086&tPage=3&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking