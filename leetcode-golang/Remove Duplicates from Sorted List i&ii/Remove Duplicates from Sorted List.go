//删除链表中重复的元素，保留一个
func deleteDuplicates(head *ListNode) *ListNode {
    if head == nil {
        return nil
    }
    temp := head
    for temp != nil && temp.Next != nil {
        if temp.Val == temp.Next.Val {
            temp.Next = temp.Next.Next
        } else {
            temp = temp.Next
        }
    }
    return head
}


//删除链表中重复的元素，一个都不留
func deleteDuplicates(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	dummy := new(ListNode)
	dummy.Next = head
	p := dummy
	for head != nil && head.Next != nil {
		if head.Val == head.Next.Val {
			for head.Next != nil && head.Val == head.Next.Val {
				head = head.Next
			}
			p.Next = head.Next
			head = head.Next
		} else {
			head = head.Next
			p = p.Next
		}
	}
	return dummy.Next
}