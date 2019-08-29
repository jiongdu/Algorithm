/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func isBalanced(root *TreeNode) bool {
    if height(root) == -1 {
        return false
    }
    return true
}

func height(root *TreeNode) int {
    if root == nil {
        return 0
    }
    left := height(root.Left)
    right := height(root.Right)
    if left == -1 || right == -1 || math.Abs(float64(left)-float64(right)) > 1 {
        return -1
    }
    return int(math.Max(float64(left), float64(right)) + 1)
}
