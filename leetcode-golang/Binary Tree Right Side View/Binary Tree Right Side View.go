type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//同样是层次遍历，取每一行node中最大的一个
//如果是左视图的话，就取每一行node中最小的一个
func rightSideView(root *TreeNode) []int {
    if root == nil {
		return []int{}
	}
	nodes := []*TreeNode{root}
	result := []int{}
	for len(nodes) > 0 {
		copyNodes := nodes[:]
		nodes = []*TreeNode{}
		for i, node := range copyNodes {
			if i ==  len(copyNodes) - 1 {
				result = append(result, node.Val)
			}
			if node.Left != nil {
				nodes = append(nodes, node.Left)
			}
			if node.Right != nil {
				nodes = append(nodes, node.Right)
			}
		}
	}
	return result
}