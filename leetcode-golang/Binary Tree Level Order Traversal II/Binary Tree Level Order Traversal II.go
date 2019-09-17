/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
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
		//还有一种，只需要在这里改一行代码，不需要下面的reverseLevel
		//即在数组的前面插入，不过要注意语法
		//result = append([][]int{levelSlice}, result...)
	}
	reverseLevel(result)
	return result
}

func reverseLevel(result [][]int) {
	for i := 0; i < len(result)/2; i++ {
		result[i], result[len(result)-i-1] = result[len(result)-i-1], result[i]
	}
}