题目描述:
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?
For example,
Given sorted array A =[1,1,1,2,2,3],
Your function should return length =5, and A is now[1,1,2,2,3].

题目解析:
超过连续两个的才被称为“连续”，因此，改变判定条件if(A[i]==A[i+1] && A[i]==A[i+2])做小改变即可。

题目地址:
http://www.nowcoder.com/practice/567f420f12ed4069b7e1d1520719d409?tpId=46&tqId=29098&tPage=3&rp=3&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking