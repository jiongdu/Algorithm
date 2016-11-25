题目描述:
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

题目解析:
使用hash表保存roman和num之间的对应关系。只有一种情况需要特殊关注，即该位的数比上一位大，比如IV，要涉及到减法。

题目地址:
http://www.nowcoder.com/practice/817fdd12bd3341349a0079f74e692ebf?tpId=46&tqId=29165&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking