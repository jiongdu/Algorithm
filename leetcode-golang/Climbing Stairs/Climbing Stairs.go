func climbStairs(n int) int {
	if n == 0 || n == 1 || n == 2 {
		return n
	}
	dp := make([]int, n+1, n+1)
	dp[0], dp[1], dp[2] = 0, 1, 2
	for i := 3; i <= n; i++ {
		dp[i] = dp[i-1] + dp[i-2] //从i-1爬两个台阶+从i-2爬1个台阶
	}
	return dp[n]
}