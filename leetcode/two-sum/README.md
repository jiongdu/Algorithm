题目描述:
Given an array of integers, find two numbers such that they add up to a specific target number.
The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

题目解析:
使用map存储，每存一个时，看map中是否已经存在和其相加等于target的数。

题目地址:
http://www.nowcoder.com/practice/20ef0972485e41019e39543e8e895b7f?tpId=46&tqId=29177&rp=7&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking