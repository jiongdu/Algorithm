import "strconv"

func largestTimeFromDigits(A []int) string {
	perm := make([]string, 0, 24)
	used := make([]bool, 4, 4)
	dfs(used, "", A, &perm)
	maxVal := 0
	res := ""
	for _, s := range perm {
		h, _ := strconv.Atoi(s[:2])
		m, _ := strconv.Atoi(s[2:])
		if h <= 23 && m <= 59 {
			if h*100+m >= maxVal {
				maxVal = h*100 + m
				res = s[:2] + ":" + s[2:]
			}
		}
	}
	return res
}

func dfs(used []bool, curr string, A []int, perm *[]string) {
	if len(curr) == 4 {
		*perm = append(*perm, curr)
		return
	}
	for i := 0; i < 4; i++ {
		if !used[i] {
			used[i] = true
			s := strconv.Itoa(A[i])
			dfs(used, curr+s, A, perm)
			used[i] = false
		}
	}
}