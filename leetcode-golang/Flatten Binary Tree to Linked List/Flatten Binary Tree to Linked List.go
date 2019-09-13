/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

//slice足够处理queue和stack的场景
func flatten(root *TreeNode) {
	if root == nil {
		return
	}
	nodes := []*TreeNode{root}
	for len(nodes) > 0 {
		node := nodes[len(nodes)-1]
		nodes = nodes[0 : len(nodes)-1]
		if node != root {
			root.Right = node
			root.Left = nil
			root = root.Right
		}
		if node.Right != nil {
			nodes = append(nodes, node.Right)
		}
		if node.Left != nil {
			nodes = append(nodes, node.Left)
		}
	}
}