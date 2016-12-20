题目描述:
The set[1,2,3,…,n]contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
"123"
"132"
"213"
"231"
"312"
"321"

Given n and k, return the k th permutation sequence.
Note: Given n will be between 1 and 9 inclusive.

题目解析:
比较简单，只是注意这里是对字符串来进行排列。
使用STL算法next_permutation。

题目地址:
https://www.nowcoder.com/practice/186c35e87f7b45beaa556dbbf670759e?tpId=46&tqId=29119&tPage=7&rp=7&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking