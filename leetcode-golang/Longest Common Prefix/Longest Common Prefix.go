//不要想多了，就是最朴实的算法，写出来即可
func longestCommonPrefix(strs []string) string {
	length := len(strs)
	if length == 0 {
		return ""
	}
	if length == 1 {
		return strs[0]
	}
	temp := strs[0]
	res := ""
	for i := 0; i < len(temp); i++ {
		for j := 1; j < length; j++ {
			if i >= len(strs[j]) || temp[i] != strs[j][i] {
				return res
			}
		}
		res = res + string(temp[i])
	}
	return res
}