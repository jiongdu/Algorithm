func reverseBetween(head *ListNode, m int, n int) *ListNode {
	if head == nil {
		return nil
	}
	dummy := &ListNode{
		Next: head,
	}
	prev := dummy
	i := 1
	//prev在m对应节点的前一个
	for prev != nil && i < m {
		prev = prev.Next
		i++
	}
	cur := prev.Next
	for cur != nil && i < n {
		temp := cur.Next
		//prev.Next = temp  这样当然不行，真是败笔，后面还用到了temp.Next = prev.Next
		cur.Next = temp.Next
		temp.Next = prev.Next
		prev.Next = temp
	}
	return dummy.Next
}