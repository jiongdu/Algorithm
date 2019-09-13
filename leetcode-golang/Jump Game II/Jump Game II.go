//按照Jump Game I保存数组的方法还是可以做对

func jump(nums []int) int {
	INT_MAX := int(^uint(0) >> 1)
	dp := make([]int, len(nums), len(nums))
	dp[0] = 0
	for i := 1; i < len(nums); i++ {
		dp[i] = INT_MAX
	}
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j <= nums[i]+i && j < len(nums); j++ {
			dp[j] = min(dp[j], dp[i]+1)
		}
	}
	return dp[len(nums)-1]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

//贪心算法
//重点不在于判断当前位置跳几步，而是要记录在当前位置可以到达的范围内，下一跳可以到达的最远位置
func jump(nums []int) int {
	left, right := 0, 0 //每次跳跃能到达的左边界、右边界
	result := 0
	for right < len(nums)-1 {
		maxJump := right
		for i := left; i <= right; i++ {
			maxJump = max(maxJump, nums[i]+i)
		}
		left = right + 1
		right = maxJump
		result++
	}
	return result
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}