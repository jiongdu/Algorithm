import "sort"

func threeSum(nums []int) [][]int {
	var result [][]int
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue //避免重复，只能避免初始点
		}
		//O(N2)的时间复杂度，两根指针去找两个数相加等于nums[i]
		target, left, right := -nums[i], i+1, len(nums)-1
		for left < right {
			if nums[left]+nums[right] == target {
				result = append(result, []int{nums[i], nums[left], nums[right]})
				left++
				right--
				//再次去重
				for left < right && nums[left] == nums[left-1] {
					left++
				}
				for left < right && nums[right] == nums[right+1] {
					right--
				}
			} else if nums[left]+nums[right] < target {
				left++
			} else {
				right--
			}
		}
	}
	return result
}