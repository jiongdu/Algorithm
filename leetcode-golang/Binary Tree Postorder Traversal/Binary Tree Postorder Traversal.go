type TreeNode struct {
	Val int
	Left *TreeNode
	Right *TreeNode
}

//非递归的方式
func postorderTraversal(root *TreeNode) []int {
    ret := []int{}
    if root == nil {
        return ret
    }
    nodes := []*TreeNode{}
    var r *TreeNode = nil
    for len(nodes)>0 || root != nil {
        if root != nil {
            nodes = append(nodes, root)
            root = root.Left
        } else {
            root = nodes[len(nodes)-1]
            if root.Right != nil && root.Right != r {
                root = root.Right
                nodes = append(nodes, root)
                root = root.Left
            } else {
                ret = append(ret, root.Val)
                nodes = nodes[:len(nodes)-1]
                r = root
                root = nil
            }
        }
    }
    return ret
}

//递归的方式
func postorderTraversal(root *TreeNode) []int {
	var result []int
	if root == nil {
		return result
	}
	result = append(result, postorderTraversal(root.Left)...)
	result = append(result, postorderTraversal(root.Right)...)
	result = append(result, root.Val)
	return result
}


