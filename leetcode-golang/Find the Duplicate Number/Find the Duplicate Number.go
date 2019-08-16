func findDuplicate(nums []int) int {
	left, right := 0, len(nums)-1
	for left < right {
		mid := (left + right) / 2
		count := 0
		for _, num := range nums {
			if num <= mid {
				count++
			}
		}
		if count > mid {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return left
}
// func findDuplicate(nums []int) int {
// 	sort.Ints(nums)
// 	for i := 1; i < len(nums); i++ {
// 		if nums[i] == nums[i-1] {
// 			return nums[i]
// 		}
// 	}
// 	return 0
// }