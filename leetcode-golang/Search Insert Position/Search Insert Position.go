func searchInsert(nums []int, target int) int {
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] < target {
			// if mid+1 < len(nums) && nums[mid+1] > target {
			// 	return mid + 1
			// }
			left = mid + 1
		} else {
			// if mid-1 >= 0 && nums[mid-1] < target {
			// 	return mid
			// }
			right = mid - 1
		}
	}
	return left
}