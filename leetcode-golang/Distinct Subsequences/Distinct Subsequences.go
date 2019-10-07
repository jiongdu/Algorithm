func numDistinct(s string, t string) int {
	n, m := len(s), len(t)
	dp := make([][]int, n+1)
	for i := 0; i < n+1; i++ {
		dp[i] = make([]int, m+1)
	}

	for i := 0; i < n+1; i++ {
		dp[i][0] = 1
	}
	//默认即为0
	//for j := 1; j < m+1; j++ {
	//	dp[0][j] = 0
	//}
	for i := 1; i < n+1; i++ {
		for j := 1; j < m+1; j++ {
			if s[i-1] == t[j-1] {
				dp[i][j] = dp[i-1][j] + dp[i-1][j-1]
			} else {
				dp[i][j] = dp[i-1][j]
			}
		}
	}
	return dp[n][m]
}