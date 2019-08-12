func partition(s string) [][]string {
	result := [][]string{}
	cur := []string{}
	dfs(&result, cur, 0, s)
	return result
}

func dfs(result *[][]string, cur []string, start int, s string) {
    if start == len(s) {
		*result = append(*result, append([]string{}, cur...))
		return
	}
	for i := start; i < len(s); i++ {
		//先判断切出来的子串是不是回文串
		subStr := s[start:i+1]
		//如果是，再递归
		if isPal(subStr) {
			cur = append(cur, subStr)
			dfs(result, cur, i+1, s)
			cur = cur[:len(cur)-1]
		}
	}
}

func isPal(s string) bool {
	if len(s) == 0 {
		return true
	}
	left, right := 0, len(s)-1
	for left <= right {
		if s[left] != s[right] {
			return false
		} else {
			left, right = left+1, right-1
		}
	}
	return true
}