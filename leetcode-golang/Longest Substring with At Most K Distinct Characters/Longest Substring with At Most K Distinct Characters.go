//最多有k个不同字符的字符串，同样是滑动窗口的方法
func lengthOfLongestSubstringKDistinct(s string, k int) int {
	m := make(map[byte]int)
	start, maxLen := 0, 0
	for end := 0; end < len(s); end++ {
		m[s[end]]++
		for start < len(s) && len(m) > k { //同样if也可以
			m[s[start]]--
			if m[s[start]] == 0 { //要delete
				delete(m, s[start])
			}
			start++
		}
		if len(m) <= k {
			maxLen = max(maxLen, end-start+1)
		}
	}
	return maxLen
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
