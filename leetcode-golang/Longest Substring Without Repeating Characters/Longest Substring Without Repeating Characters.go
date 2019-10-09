import "strings"

func lengthOfLongestSubstring(s string) int {
	maxLen, start, end := 0, 0, 0
	for start < len(s) && end < len(s) {
		if !strings.Contains(s[start:end], string(s[end])) {
			end++
			if end-start > maxLen {
				maxLen = end - start
			}
		} else {
			start++
		}
	}
	return maxLen
}

//另外的方法
func lengthOfLongestSubstring(s string) int {
	maxLen := 0
	m := make(map[byte]int, 0)
	pre := -1
	for i := 0; i < len(s); i++ {
		//之前已经出现过
		if index, ok := m[s[i]]; ok {
			pre = max(pre, index) //这一步很关键，取当前的最近pre和s[i]之前出现过的index二者的最大值
		}
		maxLen = max(maxLen, i-pre)
		m[s[i]] = i
	}
	return maxLen
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}