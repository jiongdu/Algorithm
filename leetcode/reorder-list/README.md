题目描述:
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given{1,2,3,4}, reorder it to{1,4,2,3}.

题目解析:
原地排序，所以最好不使用栈之类的辅助数据结构。思路是，仍然先使用“快、慢”指针找出链表的中间点。然后对后半部分进行反转，最后按题目要求调整顺序。

题目地址:
http://www.nowcoder.com/practice/3d281dc0b3704347846a110bf561ef6b?tpId=46&tqId=29037&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking