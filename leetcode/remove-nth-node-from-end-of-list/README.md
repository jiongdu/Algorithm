题目描述:
Given a linked list, remove the nth node from the end of list and return its head.
For example,
	Given linked list: 1->2->3->4->5, and n = 2.

   	After removing the second node from the end, the linked list becomes 1->2->3->5.

题目解析:
主要的问题是找到从最后开始倒数第n个节点的位置，仍然采用“快、慢”指针的方法，让快指针在满指针前面n处，当快指针到最后一个元素时，慢指针正是倒数第n个节点的位置。然后，进行指针操作，删除元素。

题目地址:
http://www.nowcoder.com/practice/f95dcdafbde44b22a6d741baf71653f6?tpId=46&tqId=29159&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking