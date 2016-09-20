题目描述:
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are+,-,*,/. Each operand may be an integer or another expression.
Some examples:
	["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  	["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

题目解析:
栈的典型使用，遇到数就入栈，遇到操作符就弹出两个数进行运算，并将运算结果入栈。只是注意题目中输入是vector<string>，其实vector<char>更好。

题目地址:
http://www.nowcoder.com/practice/22f9d7dd89374b6c8289e44237c70447?tpId=46&tqId=29031&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking