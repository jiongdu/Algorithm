/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func hasPathSum(root *TreeNode, sum int) bool {
	if root == nil {
		return false
	}
	if root.Val == sum && root.Left == nil && root.Right == nil {
		return true
	}
	return hasPathSum(root.Left, sum-root.Val) || hasPathSum(root.Right, sum-root.Val)
}

//也是递归+回溯的套路
func pathSum(root *TreeNode, sum int) [][]int {
	result := make([][]int, 0)
	tempArr := make([]int, 0)
	helper(root, sum, &result, tempArr)
	return result
}
func helper(root *TreeNode, sum int, result *[][]int, tempArr []int) {
	if root == nil {
		return
	}
	if root.Val == sum && root.Left == nil && root.Right == nil {
		tempArr = append(tempArr, root.Val)
		*result = append(*result, append([]int{}, tempArr...))
		//*result = append(*result, tempArr)        //深拷贝和浅拷贝
		return
	}
	helper(root.Left, sum-root.Val, result, append(tempArr, root.Val))
	helper(root.Right, sum-root.Val, result, append(tempArr, root.Val))
}