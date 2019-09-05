//O(lgN)的时间复杂度
//两种情况都会有半边是有序的
func search(nums []int, target int) int {
	if len(nums) <= 0 {
		return -1
	}
	left, right := 0, len(nums)-1
	for left <= right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		}
		//left <= mid,这样在左边就是递增序列，左边升序
		if nums[left] <= nums[mid] {
			//判断是否在左边升序的子序列中
			if nums[left] <= target && target < nums[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else { //右边升序
			//判断是否在右边升序的子序列中
			if nums[mid] < target && target <= nums[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		}
	}
	return -1
}