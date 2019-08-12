func findTargetSumWays(nums []int, S int) int {
	n := len(nums)
	result := make([]map[int, int], n+1)
	result[0][0] = 1
	for i:=0; i<n; i++ {
		for k, v := range dp[i] {
			sum := k
			count := v
			result[i+1][sum+nums[i]] += count
			result[i+1][sum-nums[i]] += count
		}
	}
	return result[n][S]
}