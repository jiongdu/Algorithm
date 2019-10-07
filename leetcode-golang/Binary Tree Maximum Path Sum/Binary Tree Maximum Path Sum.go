/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func maxPathSum(root *TreeNode) int {
    ans := math.MinInt32
    dfs(root, &ans)
    return ans
}

func dfs(root *TreeNode, ans *int) int {
    if root == nil {
        return 0
    }
    left := max(0, dfs(root.Left, ans))
    right := max(0, dfs(root.Right, ans))
    *ans = max(*ans, left + right + root.Val)
    return max(left, right) + root.Val
}

func max(i, j int) int {
    if i > j {
        return i
    }
    return j
}