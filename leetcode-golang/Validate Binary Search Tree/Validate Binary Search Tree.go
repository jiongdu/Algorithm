/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// [10,5,15,null,null,6,20]
 func isValidBST(root *TreeNode) bool {
    return isValidBSTHelper(root, nil, nil)
}

func isValidBSTHelper(root , l, r *TreeNode) bool {
	if root == nil {
		return true
	}
	if (l != nil && l.Val >= root.Val) || (r != nil && r.Val <= root.Val) {
		return false
	}
	return isValidBSTHelper(root.Left, l, root) && isValidBSTHelper(root.Right, root, r)
}