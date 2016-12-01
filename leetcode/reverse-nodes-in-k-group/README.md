题目描述:
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example,
Given this linked list:1->2->3->4->5
For k = 2, you should return:2->1->4->3->5
For k = 3, you should return:3->2->1->4->5

题目解析:
先翻转前k个，后面使用递归实现，用到了之前的链表部分翻转的函数。

题目地址:
https://www.nowcoder.com/practice/b49c3dc907814e9bbfa8437c251b028e?tpId=46&tqId=29154&tPage=4&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking