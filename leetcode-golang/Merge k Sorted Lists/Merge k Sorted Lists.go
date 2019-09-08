/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 //从合并两个链表引申过来的方法
 func mergeKLists(lists []*ListNode) *ListNode {
    if len(lists) == 0 {
        return nil
    }
    if len(lists)
    for i := 1; i < len(lists); i++ {
        lists[i] = mergeTwoLists(lists[i-1], lists[i])
    }
    return lists[len(lists)-1]
}

func mergeTwoLists(l1, l2 *ListNode) *ListNode {
    if l1 == nil && l2 == nil {
        return nil
    }
    dummy := &ListNode{}
    head := dummy
    for l1 != nil && l2 != nil {
        if l1.Val < l2.Val {
            head.Next = l1
            l1 = l1.Next
        } else {
            head.Next = l2
            l2 = l2.Next
        }
        head = head.Next
    }
    if l1 != nil {
        head.Next = l1
    }
    if l2 != nil {
        head.Next = l2
    }
    return dummy.Next
}


