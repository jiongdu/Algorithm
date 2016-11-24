题目描述:
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A =[2,3,1,1,4]
The minimum number of jumps to reach the last index is2. (Jump1step from index 0 to 1, then3steps to the last index.)

题目解析:
在jump-game的基础上，做了改进。
现在改为保存到每个index上所需的最小steps。

题目地址:
http://www.nowcoder.com/practice/7250845fb3b946a5a778565adba9d993?tpId=46&tqId=29134&tPage=2&rp=2&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking