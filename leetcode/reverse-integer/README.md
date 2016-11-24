题目描述:
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
click to show spoilers.
Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).

题目解析:
通过对数字模十取余得到它的最低位，ret = ret*10 + num%10一步步保持翻转结果。
本题重点考查的是整数相加的溢出处理，检查溢出有以下几种方法：
（1）两个正数数相加得到负数，或者两个负数相加得到正数，但某些编译器溢出或优化的方式不一样；
（2）对于正数，如果最大整数减去一个数小于另一个数，或者对于负数，最小整数减去一个数大于另一个数，则溢出。这是用减法来避免加法的溢出。
（3）使用long来保存可能溢出的结果，再与最大/最小整数相比较

拿到反转整数题目后第一步，首先问出题者尾部有0的数字反转后应该是什么形式，其次问清楚溢出时应该返回什么。
除了检查溢出返回特定值意外，还可以使用try-catch代码块排除异常。

题目地址:
http://www.nowcoder.com/practice/1a3de8b83d12437aa05694b90e02f47a?tpId=46&tqId=29171&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking