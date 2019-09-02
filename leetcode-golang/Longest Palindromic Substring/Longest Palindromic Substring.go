func longestPalindrome(s string) string {
	length := len(s)
	if length <= 1 {
		return s
	}
	dp := make([][]int, length)
	for i := 0; i < length; i++ {
		dp[i] = make([]int, length)
	}
	left, l := 0, 1

	//必然要经过O(N2)的复杂度
	for i := 0; i < length; i++ {
		for j := 0; j < i; j++ {
			if s[j] == s[i] && (dp[j+1][i-1] == 1 || i-j < 2) {
				dp[j][i] = 1
			}
			if dp[j][i] == 1 && l < i-j+1 {
				l = i - j + 1
				left = j
			}
		}
		//关键的一行啊
		dp[i][i] = 1
	}
	return s[left : left+l]
}