func sortArray(nums []int) []int {
	length := len(nums)
	for i := length/2 - 1; i >= 0; i-- {
		adjustHeap(nums, i, length)
	}
	for i := length - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		adjustHeap(nums, 0, i)
	}
	return nums
}

func adjustHeap(nums []int, start, length int) {
	current := nums[start]
	child := 2*start + 1
	for child < length {
		if child+1 < length && nums[child] < nums[child+1] {
			child++
		}
		if current < nums[child] {
			nums[start] = nums[child]
			start = child
			child = start*2 + 1
		} else {
			break
		}
	}
	nums[start] = current
}