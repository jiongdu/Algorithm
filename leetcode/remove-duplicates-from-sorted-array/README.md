题目描述:
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array A =[1,1,2],
Your function should return length =2, and A is now[1,2].

题目解析:
很简单的一道题，使用count来记录个数。
其实，还是觉得有问题，并没有将count后面的数字删除，还是在A数组中保留了。

题目地址:
http://www.nowcoder.com/practice/a519784e89fb40199fbe7993786715b1?tpId=46&tqId=29153&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking