/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || head <= 1 {
		return head
	}
	cur := head
	nodesLen := 0
	for cur != nil {
		nodesLen++
		cur = cur.Next
	}
	dummp := &ListNode{
		Next: head,
	}
	pre := dummy
	for ; nodesLen >= k; nodesLen -= k {
		cur := pre.Next
		for i := 1; i < k; i++ {
			temp := cur.Next
			cur.Next = temp.Next
			temp.Next = pre.Next
			pre.Next = temp
		}
		pre = cur
		cur = cur.Next
	}
	return dummy.Next
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	cur := head
	for i := 0; i < k; i++ {
		if cur == nil {
			return head
		}
		cur = cur.Next
	}
	newHead := reverse(head, cur)
	head.Next = reverseKGroup(cur, k) //cur保存的是下一段链表的开始节点
	return newHead
}

func reverse(head *ListNode, tail *ListNode) *ListNode {
	pre := new(ListNode) //pre := tail
	for head != tail {
		temp := head.Next
		head.Next = pre
		pre = head
		head = temp
	}
	return pre
}

// func reverseList(head *ListNode) *ListNode {
//     if head == nil || head.Next == nil {
//         return head
//     }
//     var prev *ListNode
//     for head != nil {
//         n := head.Next
//         head.Next = prev
//         prev = head
//         head = n
//     }
//     return prev
// }

//非递归，较难理解
//以1->2->3->4->5，k=3为例进行分析
func reverseKGroup(head *ListNode, k int) *ListNode {
	if head == nil || k <= 1 {
		return head
	}
	cur := head
	nodesLen := 0
	for cur != nil {
		nodesLen++
		cur = cur.Next
	}
	dummy := &ListNode{
		Next: head,
	}
	pre := dummy
	for ; nodesLen >= k; nodesLen -= k {
		cur := pre.Next
		for i := 1; i < k; i++ {
			temp := cur.Next
			cur.Next = temp.Next
			temp.Next = pre.Next
			pre.Next = temp
		}
		pre = cur
		cur = cur.Next
	}
	return dummy.Next
}