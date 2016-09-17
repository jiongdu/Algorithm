题目描述:
输入一个链表，反转链表后，输出链表的所有元素。

题目解析:
考查链表操作，防止在反转指针的过程中链表断开。所以，采用两个节点pNext和pPrev，前者用于保存当前遍历节点的下一节点（及待反转的第一个节点），防止链表断开，后者保存已经反转的链表的头节点。

题目地址:
https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking