func reverseSort(nums []int) {
	for i := 0; i < len(nums); i++ {
		j := len(nums) - 1 - i
		if i >= j {
			break
		}
		nums[i], nums[j] = nums[j], nums[i]
	}
}

//找下一个排列的方法
func nextPermutation(nums []int) {
	i := -1
	//找到从后向前，第一个降序的数字
	for i = len(nums) - 2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			break
		}
	}
	if i == -1 {
		reverseSort(nums)
		return
	}
	//从后向前，找到第一个大于nums[i]的数字
	var j int
	for j = len(nums) - 1; j > i; j-- {
		if nums[j] > nums[i] {
			break
		}
	}
	//然后交换
	nums[i], nums[j] = nums[j], nums[i]
	//i之后的逆序
	reverseSort(nums[i+1:])
}