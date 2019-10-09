func characterReplacement(s string, k int) int {
	m := make([]int, 128)
	start, max := 0, 0 //起始
	for end := 0; end < len(s); end++ {
		m[s[end]]++
		if max < m[s[end]] { //当前遍历中出现最多的相同字符
			max = m[s[end]]
		}
		if max+k <= end-start { //出现重复字符最多的次数+能允许的最多操作<=end-start，不能再容纳了
			m[s[start]]-- //start右移，要减掉左端一个
			start += 1
		} else {
			continue
		}
	}
	return len(s) - start
}

func characterReplacement(s string, k int) int {
	m := make([]int, 128)
	start, maxCount := 0, 0 //起始
	res := 0
	for end := 0; end < len(s); end++ {
		m[s[end]]++
		maxCount = max(maxCount, m[s[end]])
		for maxCount+k < end-start+1 { //for和if都能ac
			m[s[start]]--
			start++
		}
		res = max(res, end-start+1)
	}
	return res
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}