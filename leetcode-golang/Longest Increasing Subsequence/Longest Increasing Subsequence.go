func lengthOfLIS(nums []int) int {
	res := 0
	length := len(nums)
	if length <= 1 {
		return length
	}
	dp := make([]int, length)
	dp[0] = 1
	for i := 1; i < length; i++ {
		for j := 0; j < i; j++ {
			if nums[j] < nums[i] {
				dp[i] = max(dp[i], dp[j])
			}
		}
		dp[i] += 1
		res = max(dp[i], res)
	}
	return res
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}