题目描述:
用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。

题目解析:
用一个栈存储push进入的元素，另一个用作pop操作时的辅助栈。因为队列pop时是取得的最先进入的，所以将先将stack1中的元素依次放入stack2，然后取stack2的顶部元素。

题目地址:
http://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=8&tqId=11008&rp=1&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking