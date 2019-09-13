//plan A：维护了最大数组
func canJump(nums []int) bool {
	dp := make([]int, len(nums), len(nums))
	dp[0] = 1
	for i := 0; i < len(nums); i++ {
		if dp[i] == 1 {
			for j := i; j <= nums[i]+i; j++ {
				dp[j] = 1
				if j == len(nums)-1 {
					return true
				}
			}
		}
	}
	return dp[len(nums)-1] == 1
}

//plan B：不用维护数组，直接记录能到达的最大距离即可
func canJump(nums []int) bool {
	reach := 0
	for i := 0; i < len(nums); i++ {
		if i <= reach {
			reach = max(reach, nums[i]+i)
			if reach >= len(nums)-1 {
				return true
			}
		}
	}
	return false
}

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}

func jump(nums []int) int {
	INT_MAX = int(^uint(0) >> 1)
	dp := make([]int, len(nums), len(nums))
	for i := 0; i < len(nums); i++ {
		dp[i] = INT_MAX
	}
	dp[0] = 0
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j <= nums[i]+i; j++ {
			dp[j] = min(dp[j], dp[i]+1)
		}
	}
	return dp[len(nums)-1]
}