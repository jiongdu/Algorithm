题目描述:
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
For example, given:
S:"barfoothefoobarman"
L:["foo", "bar"]
You should return the indices:[0,9].
(order does not matter).

题目解析:
有点难度，每次从S中选择L所包含字符长度的字串，来比较是否满足一个级联，用到hash容器unordered_map。

题目地址:
https://www.nowcoder.com/practice/69ad067708c14c248f9cb9b7b6553e8f?tpId=46&tqId=29149&tPage=7&rp=7&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking