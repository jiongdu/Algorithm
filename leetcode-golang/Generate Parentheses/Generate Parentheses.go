func generateParenthesis(n int) []string {
	left, right := n, n //剩余两个符号：(和)的个数
	res := []string{}
	cur := []byte{}
	helper(left, right, cur, &res)
	return res
}

func helper(left, right int, cur []byte, res *[]string) {
	if left > right {
		return
	}
	if left == 0 && right == 0 {
		*res = append(*res, string(cur))
	} else {
		if left > 0 {
			helper(left-1, right, append(cur, '('), res)
		}
		if right > 0 {
			helper(left, right-1, append(cur, ')'), res)
		}
	}
	return
}