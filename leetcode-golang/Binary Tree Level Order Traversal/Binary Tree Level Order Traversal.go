//二叉树的层次遍历

type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return [][]int{}
	}
	result := [][]int{}
	nodes := []*TreeNode{root}
	for len(nodes) > 0 {
		levelSlice := []int{}
		nodesCopy := nodes[:]
		nodes = []*TreeNode{}
		for _, node := range nodesCopy {
			levelSlice = append(levelSlice, node.Val)
			if node.Left != nil {
				nodes = append(nodes, node.Left)
			}
			if node.Right != nil {
				nodes = append(nodes, node.Right)
			}
		}
		result = append(result, levelSlice)
	}
	return result
}