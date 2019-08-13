/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
		return head
	}
	oddList, evenList := head, head.Next
	retEventNodes := head.Next
	for evenList != nil && evenList.Next != nil {
		oddList.Next = evenList.Next
		evenList.Next = oddList.Next.Next
		oddList = oddList.Next
		evenList = evenList.Next
	}

	//oddList为奇链表的头部，retEventNodes为偶数链表的头部
	oddList.Next = retEventNodes
	return head
}