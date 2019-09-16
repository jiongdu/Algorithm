//旋转3次的方法
func rotate(nums []int, k int) {
	if len(nums) == 0 || k == 0 {
		return
	}
	//先除了之后再算
	k = k % len(nums)
	reverse(nums, 0, len(nums)-1)
	reverse(nums, 0, k-1)
	reverse(nums, k, len(nums)-1)
}

func reverse(nums []int, start, end int) {
	for start < end {
		nums[start], nums[end] = nums[end], nums[start]
		start++
		end--
	}
}

// 每次保留最后一个数，将其放到nums[0]的位置上，真正的移动k次
func rotate(nums []int, k int) {
	if len(nums) == 0 || k <= 0 {
		return
	}
	for c := 0; c < k; c++ {
		tmp := nums[len(nums)-1]
		for i := len(nums) - 2; i >= 0; i-- {
			nums[i+1] = nums[i]
		}
		nums[0] = tmp
	}
}