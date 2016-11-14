题目描述:
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
click to show follow up.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?

题目解析:
很好的一套题，空间复杂度从O(m*n)-->O(m+n)-->O(1)逐步优化。最后的方法很巧，使用第一行和第一列保存行和列需要置0的情况。
时间复杂度都为O(m*n)

题目地址:
http://www.nowcoder.com/practice/9ff9256075a1498fb165b583d951ebd4?tpId=46&tqId=29105&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking