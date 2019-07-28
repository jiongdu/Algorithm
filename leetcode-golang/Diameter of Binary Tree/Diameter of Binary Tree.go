/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

 //二叉树的直径，即三个值中的最大值：
 //每个结点求出其左右子树深度之后，再对左右子节点分别调用求直径递归函数，三者求最大
 //因为直径不一定会经过根节点，所以才要对左右子节点再分别计算一次。
 var maxDiameter int
 func MaxDeepth(t *TreeNode) (deepth int)  {
	 if nil == t {
		 return 0
	 }
 
	 left := MaxDeepth(t.Left)
	 right := MaxDeepth(t.Right)
	 //三者中的最大值
	 maxDiameter = int(math.Max(float64(maxDiameter), float64(left + right)))
	 //左节点和有节点的最大深度之和
	 return  int(math.Max(float64(left), float64(right))) + 1
 }
 
 func diameterOfBinaryTree(root *TreeNode) int {
	 maxDiameter = 0		//leetcode,golang在入口处做初始化
	 if nil == root {
		 return 0
	 }
 
	 MaxDeepth(root)
 
	 return maxDiameter
 }