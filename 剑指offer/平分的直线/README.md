题目描述:
在二维平面上，有两个正方形，请找出一条直线，能够将这两个正方形对半分。假定正方形的上下两条边与x轴平行。
给定两个vecotrA和B，分别为两个正方形的四个顶点。请返回一个vector，代表所求的平分直线的斜率和截距，保证斜率存在。
测试样例：
[(0,0),(0,1),(1,1),(1,0)],[(1,0),(1,1),(2,0),(2,1)]
返回：[0.0，0.5]

题目解析:
所求直线肯定经过两个正方形的中心点，利用两个中心点的坐标确定直线的斜率与截距即可。

题目地址:
http://www.nowcoder.com/practice/e51af77572f74a5fa069b4d5a3a0953e?tpId=8&tqId=11029&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking