/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }
    slow, fast := head, head.Next
    for fast != nil && fast.Next != nil {
        slow = slow.Next
        fast = fast.Next.Next
    }
    right := reverseList(slow.Next)
    for right != nil {
        if right.Val != head.Val {
            return false
        } else {
            right = right.Next
            head = head.Next
        }
    }
    return true
}

func reverseList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }
    var prev *ListNode
    for head != nil {
        n := head.Next
        head.Next = prev
        prev = head
        head = n
    }
    return prev
}