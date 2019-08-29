/**
 * Definition for TreeNode.
 * type TreeNode struct {
 *     Val int
 *     Left *ListNode
 *     Right *ListNode
 * }
 */
 //从根节点开始遍历，如果node1和node2中的任一个和root匹配，那么root就是最低公共祖先；
 //如果都不匹配，则分别递归左、右子树，如果有一个节点出现在左子树，并且另一个节点出现在右子树，则root就是最低公共祖先
 //如果两个节点都出现在左子树，则说明最低公共祖先在左子树中，否则在右子树
 func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	if root == p || root == q {
		return root
	}
	left := lowestCommonAncestor(root.Left, p, q)
	right := lowestCommonAncestor(root.Right, p, q)
	if left != nil && right != nil {
		return root
	} else if left  != nil && right == nil {
		return left
	} else if left == nil && right != nil {
		return right
	}
	return nil
}