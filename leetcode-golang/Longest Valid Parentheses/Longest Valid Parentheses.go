//start记录的是合法子串的起始位置
func longestValidParentheses(s string) int {
	res, start := 0, 0
	stack := make([]int, 0)
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, i)
		} else if s[i] == ')' {
			if len(stack) == 0 {
				start = i + 1
			} else {
				stack = stack[:len(stack)-1]
				if len(stack) == 0 {
					res = max(res, i-start+1)
				} else {
					res = max(res, i-stack[len(stack)-1])
				}
			}
		}
	}
	return res
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
