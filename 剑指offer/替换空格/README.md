题目描述:
请实现一个函数，将一个字符串中的空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。

题目解析:
先遍历一次字符串，统计出字符串中空格的总数，并由此计算出替换之后的字符串的总长度。在替换时，维持两个指针，从字符串的后面开始复制和替换。

题目地址:
https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking