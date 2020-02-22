package BinarySearchTree

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func searchRange(root *TreeNode, k1 int, k2 int) []int {
	// write your code here
	res := make([]int, 0)
	searchRangeHelp(root, k1, k2, &res)
	return res
}

func searchRangeHelp(root *TreeNode, k1, k2 int, res *[]int) {
	if root == nil {
		return
	}
	l := root.Val >= k1
	r := root.Val <= k2
	if l {
		searchRangeHelp(root.Left, k1, k2, res)
	}
	if l && r {
		*res = append(*res, root.Val)
	}
	if r {
		searchRangeHelp(root.Right, k1, k2, res)
	}
}
