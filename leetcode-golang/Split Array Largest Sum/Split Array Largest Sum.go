package splitArray

import "math"

func splitArray(nums []int, m int) int {
	if len(nums) == 0 {
		return 0
	}
	n := len(nums)
	sums := make([]int, n)
	sums[0] = nums[0]
	for i := 1; i < n; i++ {
		sums[i] = sums[i-1] + nums[i]
	}
	dp := make([][]int, m+1)
	for i := range dp {
		dp[i] = make([]int, n)
	}
	for i := 0; i < m+1; i++ {
		for j := 0; j < n; j++ {
			dp[i][j] = math.MaxInt32
		}
	}
	for i := 0; i < n; i++ {
		dp[1][i] = sums[i]
	}
	//dp[i][j]表示前j个元素i个划分时的最大值的最小值，j由k来划分
	for i := 2; i <= m; i++ {
		for j := i - 1; j < n; j++ {
			for k := 0; k < j; k++ {
				dp[i][j] = min(dp[i][j], max(dp[i-1][k], sums[j]-sums[k]))
			}
		}
	}
	return dp[m][n-1]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}
