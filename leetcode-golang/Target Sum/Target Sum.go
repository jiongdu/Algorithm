func findTargetSumWays(nums []int, S int) int {
	n := len(nums)
	//result[i][j]表示前i-1个数字且和为j的情况
	result := make([]map[int]int, n+1)
	for i := 0; i < len(result); i++ {
		result[i] = make(map[int]int)
	}
	result[0][0] = 1
	for i := 0; i < n; i++ {
		for k, v := range result[i] {
			sum := k
			count := v
			result[i+1][sum+nums[i]] += count
			result[i+1][sum-nums[i]] += count
		}
	}
	return result[n][S]
}

//result[S]表示和为S的情况
func findTargetSumWays(nums []int, S int) int {
	result := make(map[int]int)
	result[0] = 1
	for _, num := range nums {
		temp := make(map[int]int)
		for k, v := range result {
			temp[k+num] += v
			temp[k-num] += v
		}
		result = temp
	}
	return result[S]
}