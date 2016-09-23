题目描述:
从上往下打印出二叉树的每个节点，同层节点从左至右打印。

题目解析:
每次打印一个节点的时候，如果该节点有子节点，则把该节点的子节点放到一个队列的末尾。接下来到队列的头部取出最早进入队列节点，直到队列中所有的节点都被打印出来为止。

题目地址:
http://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking