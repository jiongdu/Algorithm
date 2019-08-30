/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func swapPairs(head *ListNode) *ListNode {
    list := &ListNode{
		Next: head
	}
	for prev, node := list, list.Next; node != nil ; node = node.Next {
		if node.Next != nil {
			swapNode(prev, node, node.Next)
			prev = node
		}
	}
	return list.Next
}

//每两个相邻节点交换
func swapNode(prev, node, next *ListNode) {
	prev.Next = next
	node.Next = next.Next
	next.Next = node
}