type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//递归的方式
func preorderTraversal(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}
	result = append(result, root.Val)
	result = append(result, preorderTraversal(root.Left)...)
	result = append(result, preorderTraversal(root.Right)...)
	return result
}

//二叉树的遍历，之前用stack/queue，现在用golang中的slice也可以巧妙完成
func preorderTraversal(root *TreeNode) []int {
    if root == nil {
		return []int{}
	}
	result := []int{}
	nodes := []*TreeNode{root}
	for len(nodes) > 0 {
		//每次取最后一个，所以塞入最后一个的应该是Left
		node := nodes[len(nodes)-1]
		nodes = nodes[:len(nodes)-1]
		result = append(result, node.Val)
		if node.Right != nil {
			nodes = append(nodes, node.Right)
		}
		if node.Left != nil {
			nodes = append(nodes, node.Left)
		}
	}
	return result
}