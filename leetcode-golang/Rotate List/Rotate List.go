/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || k == 0 {
		return head
	}
	temp := head
	length := 0
	for temp != nil {
		length++
		temp = temp.Next
	}
	if k >= length {
		k = k % length
	}
	if k == 0 {
		return head
	}
	slow, fast := head, head
	for i := 0; i < k; i++ {
		fast = fast.Next
	}
	for fast.Next != nil {
		fast = fast.Next
		slow = slow.Next
	}
	newHead := slow.Next
	slow.Next = nil
	fast.Next = head
	return newHead

}