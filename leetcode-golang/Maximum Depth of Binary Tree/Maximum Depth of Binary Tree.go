type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//bingo
func maxDepth(root *TreeNode) int {
    if root == nil {
		return 0
	}
	left, right := 1, 1
	left += maxDepth(root.Left)
	right += maxDepth(root.Right)
	return int(math.Max(float64(left), float64(right)))
}