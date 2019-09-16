func numDecodings(s string) int {
	if s[0] == '0' {
		return 0
	}
	length := len(s)
	dp := make([]int, length+1)
	//dp[i]表示是s[:i]的组成方式数
	dp[0], dp[1] = 1, 1
	lastOne, lastTwo := int(s[0]-'0'), 0
	for i := 2; i <= length; i++ {
		last := int(s[i-1] - '0')
		lastOne, lastTwo = last, lastOne*10+last
		if lastOne >= 1 {
			dp[i] = dp[i-1]
		}
		if 10 <= lastTwo && lastTwo <= 26 {
			dp[i] += dp[i-2]
		}
	}
	return dp[length]
}