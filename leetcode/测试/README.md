题目描述:
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given1->1->2, return1->2.
Given1->1->2->3->3, return1->2->3.

题目解析:
考查链表的基本操作，比较简单，遇到连续几个节点有相同的value，就调整链表节点指向，使其只保留一个。

题目地址:
https://www.nowcoder.com/practice/c087914fae584da886a0091e877f2c79?tpId=46&tqId=29096&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking