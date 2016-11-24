题目描述:
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Follow up:
Could you do this in-place?

题目解析:
把矩阵想成一个洋葱，一圈包着一圈。
（1）外一圈每一条边比里一圈每一条边长度多2；
（2）每一条边只有边长度-1个元素需要覆盖另一条边的对应元素，因为每一条边与相邻两条边相交，一条边第一个元素旋转90度其实是覆盖这条边的最后一个元素，也是相邻边的第一个元素。

题目地址:
http://www.nowcoder.com/practice/4018c0c6d15d473e804656afcbc2c501?tpId=46&tqId=29131&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking