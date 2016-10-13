题目描述:
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。注意这次的网格中有些障碍点是不能走的。
给定一个int[][] map(C++ 中为vector >),表示网格图，若map[i][j]为1则说明该点不是障碍点，否则则为障碍。另外给定int x,int y，表示网格的大小。请返回机器人从(0,0)走到(x - 1,y - 1)的走法数，为了防止溢出，请将结果Mod 1000000007。保证x和y均小于等于50

题目解析:
在“机器人走方格I”的基础上添加了障碍物的限制。由于还是只能向右或者向下走，所以，在障碍物出现的地方dp[i][j]设为0。特别的，第一排和第一列中障碍物出现后面都为0。 
转移方程还是一样。

题目地址:
http://www.nowcoder.com/practice/b3ae8b9782af4cf29253afb2f6d6907d?tpId=8&tqId=11034&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking