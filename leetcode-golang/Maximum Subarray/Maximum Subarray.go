func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	global, local := nums[0], nums[0]
	for i := 1; i < len(nums); i++ {
		local = max(nums[i], local+nums[i]) //nums[i], local[i]+nums[i](关键)、global的最大值
		global = max(local, global)
	}
	return global
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}