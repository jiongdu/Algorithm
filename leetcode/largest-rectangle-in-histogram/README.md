题目描述:
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, given height =[2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area =10unit.

For example,
Given height =[2,1,5,6,2,3],
return10.

题目解析:
有难度的一道题。
使用栈保存递增的元素的索引，当遇到较小的元素后，依次出栈并计算栈中能围成的面积，直到栈中元素小于当前元素。

题目地址:
https://www.nowcoder.com/practice/e3f491c56b7747539b93e5704b6eca40?tpId=46&tqId=29094&tPage=1&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking