/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func sortList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    //fast = head.Next
    slow, fast := head, head.Next
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    //slow是前半链表的最后一个节点
    right := sortList(slow.Next)
    slow.Next = nil
    left := sortList(head)
    return merge(left, right)
}

func merge(left *ListNode, right *ListNode) *ListNode {
    dummy := new(ListNode)
    cur := dummy
    for left != nil && right != nil {
        if left.Val <= right.Val {
            cur.Next = left
            left = left.Next
        } else {
            cur.Next = right
            right = right.Next
        }
        cur = cur.Next
    }
    if left != nil {
        cur.Next = left
    } else if right != nil {
        cur.Next = right
    }
    return dummy.Next
}