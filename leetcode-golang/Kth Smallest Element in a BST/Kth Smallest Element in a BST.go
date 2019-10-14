/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
	return kthSmallestDFS(root, &k)
}

func kthSmallestDFS(root *TreeNode, k *int) int {
	//递归进行中序遍历
	if root == nil {
		return -1
	}
	leftVal := kthSmallestDFS(root.Left, k)
	if *k == 0 {
		return leftVal
	}
	*k--
	if *k == 0 {
		return root.Val
	}
	rightVal := kthSmallestDFS(root.Right, k)
	return rightVal
}

//另外一种方法，使用中序遍历非递归（栈）的改进

// 一把ac
func kthSmallest(root *TreeNode, k int) int {
	if root == nil {
		return -1
	}
	nodes := []*TreeNode{root}
	cnt := 0
	for len(nodes) > 0 {
		if root != nil {
			nodes = append(nodes, root)
			root = root.Left
		} else {
			root = nodes[len(nodes)-1]
			nodes = nodes[:len(nodes)-1]
			cnt++
			if cnt == k {
				return root.Val
			}
			root = root.Right
		}
	}
	return -1
}