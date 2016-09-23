题目描述:
Given a linked list, swap every two adjacent nodes and return its head.
For example,
Given1->2->3->4, you should return the list as2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

题目解析:
仍然是指针的操作，还是注意代码的鲁棒性。 每两个一组进行指针的交换，处理完后p指向已处理完的最后一个节点，head指向待处理的第一个节点。

题目地址:
http://www.nowcoder.com/practice/64a7ee97b02042c189b35e3608e336ae?tpId=46&tqId=29155&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking