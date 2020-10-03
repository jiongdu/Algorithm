/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getAllElements(root1 *TreeNode, root2 *TreeNode) []int {
	arr1 := []int{}
	arr2 := []int{}
	var dfs func(node *TreeNode, arr *[]int)
	dfs = func(node *TreeNode, arr *[]int) {
		if node == nil {
			return
		}
		dfs(node.Left, arr)
		*arr = append(*arr, node.Val)
		dfs(node.Right, arr)
	}
	dfs(root1, &arr1)
	dfs(root2, &arr2)
	return merge(arr1, arr2)
}

func merge(arr1, arr2 []int) []int {
	res := []int{}
	p1, p2, l1, l2 := 0, 0, len(arr1), len(arr2)
	for p1 < l1 || p2 < l2 {
		if p2 >= l2 || p1 < l1 && arr1[p1] <= arr2[p2] {
			res = append(res, arr1[p1])
			p1++
		} else if p1 >= l1 || p2 < l2 && arr2[p2] < arr1[p1] {
			res = append(res, arr2[p2])
			p2++
		}
	}
	return res
}