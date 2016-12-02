题目描述:
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

题目解析:
在代码中已经做了解释，分三步进行，首先在原链表的每个节点后面添加复制节点，然后改变random指针的指向，使其指向实际的random，第三步，将复制后的链表拆分为两个链表，返回题目中需要的复制链表。

题目地址:
https://www.nowcoder.com/practice/60e43001345241ba9266cb4ee6fc6350?tpId=46&tqId=29042&tPage=4&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking