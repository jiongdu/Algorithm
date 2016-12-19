题目描述:
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
Below is one possible representation of s1 ="great":
    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.
For example, if we choose the node"gr"and swap its two children, it produces a scrambled string"rgeat".
    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that"rgeat"is a scrambled string of"great".
Similarly, if we continue to swap the children of nodes"eat"and"at", it produces a scrambled string"rgtae".
    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that"rgtae"is a scrambled string of"great".
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

题目解析:
很难，参考了别人的解法。
使用动态规划，使用f[len][i][j]表示s1起始为i，s2起始为j，长度为len的两个字串是否互为scramble string。
判断方法为：两种情况满足其一则互为scramble string。第一种是s1左边和s2[j...j+len-1]左边部分是不是scramble，以及右边和s2[j...j+len-1]右边部分是不是scramble，第二种情况是左边和s2[j...j+len-1]右边部分是不是scramble，以及右边和s2[j...j+len-1]左边部分是不是scramble。
因此，动态规划递推式是：
if ((f[k][i][j] && f[len - k][i + k][j + k]) || (f[k][i][j + len - k] && f[len - k][i + k][j])){
                   f[len][i][j]=true;
                   break;
}

题目地址:
https://www.nowcoder.com/practice/2bdc44bb0186468b8d8c13ea5d3a9e58?tpId=46&tqId=29091&tPage=4&rp=4&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking