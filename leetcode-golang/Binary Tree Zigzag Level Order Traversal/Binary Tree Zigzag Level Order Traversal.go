/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	ret := [][]int{}
	if root == nil {
		return ret
	}
	nodes := []*TreeNode{root}
	level := 1
	for len(nodes) > 0 {
		copyNodes := nodes[:]
		nodes = []*TreeNode{}
		levelRet := []int{}
		for i := len(copyNodes) - 1; i >= 0; i-- {
			node := copyNodes[i]
			if node == nil {
				continue
			}
			levelRet = append(levelRet, node.Val)
			if level%2 == 1 {
				nodes = append(nodes, node.Left, node.Right)
				// if node.Left != nil {
				//     nodes = append(nodes, node.Left)
				// }
				// if node.Right != nil {
				//     nodes = append(nodes, node.Right)
				// }
			}
			if level%2 == 0 {
				nodes = append(nodes, node.Right, node.Left)
				// if node.Right != nil {
				//     nodes = append(nodes, node.Right)
				// }
				// if node.Left != nil {
				//     nodes = append(nodes, node.Left)
				// }
			}
		}
		if len(levelRet) > 0 {
			ret = append(ret, levelRet)
		}
		level++
	}
	return ret
}

//另一种方法
func zigzagLevelOrder(root *TreeNode) [][]int {
	result := [][]int{}
	if root == nil {
		return result
	}
	nodes := []*TreeNode{root}
	level := 1
	for len(nodes) > 0 {
		copyNodes := nodes[:]
		nodes = []*TreeNode{}
		temp := []int{}
		for _, node := range copyNodes {
			if level%2 == 1 {
				temp = append(temp, node.Val)
			} else {
				temp = append([]int{node.Val}, temp...)
			}
			if node.Left != nil {
				nodes = append(nodes, node.Left)
			}
			if node.Right != nil {
				nodes = append(nodes, node.Right)
			}
		}
		result = append(result, temp)
		level++
	}
	return result
}