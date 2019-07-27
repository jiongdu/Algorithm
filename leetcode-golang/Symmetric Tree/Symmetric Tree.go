/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 func isSymmetric(root *TreeNode) bool {
    if root == nil {
        return true
    }
	return isSymmetricHelp(root.Left, root.Right)
}

func isSymmetricHelp(t1 *TreeNode, t2 *TreeNode) bool {
	if t1 == nil && t2 == nil {
		return true
	}
	if t1 == nil || t2 ==  nil {
		return false
	}
	return (t1.Val == t2.Val) && isSymmetricHelp(t1.Left, t2.Right) && isSymmetricHelp(t1.Right, t2.Left)
}