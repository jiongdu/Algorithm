/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func generateTrees(n int) []*TreeNode {
	if n == 0 {
		return []*TreeNode{}
	}
	return generator(1, n)
}

func generator(start, end int) []*TreeNode {
	if start > end {
		return []*TreeNode{nil}
	}
	nodes := make([]*TreeNode, 0)
	for i := start; i <= end; i++ {
		leftSubtrees := generator(start, i-1)
		rightSubtrees := generator(i+1, end)
		for _, left := range leftSubtrees {
			for _, right := range rightSubtrees {
				root := &TreeNode{
					Val : i,
					Left: left,
					Right: right,
				}
				nodes := append(nodes, root)
			}
		}
	}
	return nodes
}