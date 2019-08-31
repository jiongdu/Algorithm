/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}
	if k <= 1 {
		return head
	}
	nodesLen := 0
	for p := head; p != nil; p = p.Next {
		nodesLen++
	} 
    dummy := &ListNode{
        Next:head,
    }
	dummy.Next = head	
	pre := dummy
    tail, next := head, head
	for; nodesLen >= k; nodesLen-=k {
		for i := 0; i < k; i++ {
			temp := next.Next
			next.Next = pre.Next
			pre.Next = next
			next = temp
			tail.Next = next
		}
		pre = tail
		tail = next
	}
	return dummy.Next
}