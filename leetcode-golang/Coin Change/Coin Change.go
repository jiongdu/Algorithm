func coinChange(coins []int, amount int) int {
	INT_MAX := int(^uint32(0) >> 1)
	dp := make([]int, amount+1, amount+1)
	for i := range dp {
		dp[i] = INT_MAX
	}
	dp[0] = 0
	for _, coin := range coins {
		for i := coin; i <= amount; i++ {
			if dp[i-coin] != INT_MAX { //i-coin是去除掉正在遍历的这个coin（在之前的dp[i-coin]基础上+1），因此dp[i-coin]+1
				dp[i] = min(dp[i], dp[i-coin]+1)
			}
		}
	}
	if dp[amount] == INT_MAX {
		return -1
	}
	return dp[amount]
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}