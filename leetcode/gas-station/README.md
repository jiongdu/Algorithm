题目描述:
There are N gas stations along a circular route, where the amount of gas at station i isgas[i].
You have a car with an unlimited gas tank and it costscost[i]of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
Note: 
The solution is guaranteed to be unique.

题目解析:
该题的意思是求出从哪一个油站出发，能走完整个里程，并且这个结果是唯一的。     
考虑两种情况：
（1）首先可以得到所有油站的油量和totalGas,以及总里程需要消耗的油量totalCost,如果totalGas小于totalCost，那么肯定不能够走完整个里程。
（2）如果totalGas大于totalCost，那么就能走完整个里程了，假设现在到达了第i个加油站，这时候剩余的油量为sum，如果sum+gas[i]-cost[i]小于0，便无法到达下一个油站，所以起点一定不再第i个以及之前的油站里面，只能再i+1或者后面。

题目地址:
http://www.nowcoder.com/practice/3b1abd8ba2e54452b6e18b31780b3635?tpId=46&tqId=29046&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking