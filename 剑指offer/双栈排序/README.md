题目描述:
请编写一个程序，按升序对栈进行排序（即最大元素位于栈顶），要求最多只能使用一个额外的栈存放临时数据，但不得将元素复制到别的数据结构中。
给定一个int[] numbers(C++中为vector&ltint>)，其中第一个元素为栈顶，请返回排序后的栈。请注意这是一个栈，意味着排序过程中你只能访问到第一个元素。

测试样例：
[1,2,3,4,5]
返回：[5,4,3,2,1]

题目解析:
使用两个栈，对栈顶元素进行多次比较。再一些情况下，会涉及到较多的元素移动。

题目地址:
http://www.nowcoder.com/practice/d0d0cddc1489476da6b782a6301e7dec?tpId=8&tqId=11009&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking