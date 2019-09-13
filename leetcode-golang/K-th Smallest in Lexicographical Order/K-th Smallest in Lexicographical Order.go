func findKthNumber(n int, k int) int {
	cur := 1
	k--
	for k > 0 {
		step, first, last := 0, cur, cur+1 //first:1, last:2,遍历1,2之间的,十叉树的第一层节点
		//计算出first到last之间的step，示例中step为5，算step主要是因为不是满十叉树，所以需要算子节点有多少（第一层相邻节点之间的距离）
		for first <= n {
			step += min(n+1, last) - first
			first *= 10
			last *= 10
		}
		if step <= k { //继续同一层的右边节点找
			cur++
			k -= step
		} else { //就在其中
			cur *= 10
			k--
		}
	}
	return cur
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}