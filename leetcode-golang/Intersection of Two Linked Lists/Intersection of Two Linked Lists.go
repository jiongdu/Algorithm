/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 func getIntersectionNode(headA, headB *ListNode) *ListNode {
    if headA == nil || headB == nil {
        return nil
    }   
    tempA, tempB := headA, headB
    lenA, lenB := 0, 0
    for tempA != nil {
        lenA++
        tempA = tempA.Next
    }
    for tempB != nil {
        lenB++
        tempB = tempB.Next
    }
    tempA = headA
    tempB = headB
    if lenA >= lenB {
        sub := lenA-lenB
        for i:=0; i<sub; i++ {
            tempA = tempA.Next
        }
    } else {
        sub := lenB-lenA
        for i:=0; i<sub; i++ {
            tempB = tempB.Next
        }
    }
    for tempA != nil && tempB != nil {
        if tempA == tempB {
            return tempA
        }
        tempA = tempA.Next
        tempB = tempB.Next
    }
    return nil
}