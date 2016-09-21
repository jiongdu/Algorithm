题目描述:
Given an array and a value, remove all instances of that value in place and return the new length.
The order of elements can be changed. It doesn't matter what you leave beyond the new length.

题目解析:
思路还是很容易想到的，找到连续相同节点的上一个节点和下一个节点，把它们连接起来，仍然需要注意边界条件的处理，即保证代码的鲁棒性。这一点，在链表的操作中很重要。

题目地址:
http://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024?tpId=46&tqId=29095&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking