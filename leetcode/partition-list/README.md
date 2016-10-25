题目描述:
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example,
Given1->4->3->2->5->2and x = 3,
return1->2->2->4->3->5.

题目解析:
使用两个链表，分别存放比x小和大于等于x的节点，然后把他们组合起来。

题目地址:
http://www.nowcoder.com/practice/1dc1036be38f45f19000e48abe00b12f?tpId=46&tqId=29092&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking