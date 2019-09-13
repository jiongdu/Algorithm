/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//1、将原链表分成两部分
//2、第二部分链表反转
//3、将第二部分链表间隔地插入第一部分链表中
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil || head.Next.Next == nil {
		return
	}
	slow, fast := head, head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	rightHead := slow.Next
	slow.Next = nil
	//第二部分反转之后的链表
	reverseRightHead := reverseList(rightHead)
	leftHead := head
	for reverseRightHead != nil {
		leftNext, rightNext := leftHead.Next, reverseRightHead.Next
		leftHead.Next = reverseRightHead
		reverseRightHead.Next = leftNext
		leftHead = leftNext
		reverseRightHead = rightNext
	}
}

func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var prev *ListNode
	for head != nil {
		next := head.Next
		head.Next = prev
		prev = head
		head = next
	}
	return prev
}