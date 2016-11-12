题目描述:
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return[0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.
For example,[0,2,3,1]is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

题目解析:
参考了两种方法实现。
V0.1：随着n变大，前面的数不用动，后面的数倒着拿出来再在首部加1即可。    使用或操作。
V0.2：第二种方法更巧妙，对于0到1>>n - 1共n个数，每个数对应的gray码是 (i>>1)^i。

题目地址:
http://www.nowcoder.com/practice/55dddb4cdf074fefba653ff523e42346?tpId=46&tqId=29089&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking