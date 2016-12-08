题目描述:
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

题目解析:
和i相比，现在允许多次买卖，同时规定在买入之前手中不能有股票，所以，分段考虑，计算每段的最大利润。

题目地址:
https://www.nowcoder.com/practice/572903b1edbd4a33b2716f7649b4ffd4?tpId=46&tqId=29058&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking