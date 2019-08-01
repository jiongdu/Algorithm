type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//递归的方式
func inorderTravelsal(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}
	result = append(result, inorderTravelsal(root.Left)...)
	result = append(result, root.Val)
	result = append(result, inorderTravelsal(root.Right)...)
	return result
}

//二叉树的中序遍历
func inorderTraversal(root *TreeNode) []int {
    if root == nil {
		return []int{}
	}
	result := []int{}
	nodes := []*TreeNode{}
	
	for root != nil || len(nodes) > 0 {
		if root != nil {
			nodes = append(nodes, root)
			root = root.Left
		} else {
			root  = nodes[len(nodes)-1]
			nodes = nodes[:len(nodes)-1]
			result = append(result, root.Val)
			root = root.Right
		}
	}
	return result
}