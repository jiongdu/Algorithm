type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

//反转二叉树
//需要包含一个交换的操作
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	root.Left, root.Right = root.Right, root.Left
	invertTree(root.Left)
	invertTree(root.Right)
	return root
}

//所以还是要细究一下，这种方法是ok的，只是要注意保存root.Left，后面使用的时候已经不是最原始的root.Left了
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	tempNode := root.Left
	root.Left = invertTree(root.Right)
	root.Right = invertTree(tempNode)
	return root
}
