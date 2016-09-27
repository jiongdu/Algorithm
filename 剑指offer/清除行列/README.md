题目描述:
请编写一个算法，若N阶方阵中某个元素为0，则将其所在的行与列清零。
给定一个N阶方阵int[][](C++中为vector>)mat和矩阵的阶数n，请返回完成操作后的int[][]方阵(C++中为vector>)，保证n小于等于300，矩阵中的元素为int范围内。
测试样例：
[[1,2,3],[0,1,2],[0,0,1]]
返回：[[0,0,3],[0,0,0],[0,0,0]]

题目解析:
用set分别保存原数组中0所在的行和列，将其所在的行和列清零。

题目地址:
http://www.nowcoder.com/practice/c95aac1506574dfc8ad44c3939c6739d?tpId=8&tqId=11000&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking