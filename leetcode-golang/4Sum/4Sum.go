import "sort"

//还是，要去重的地方略多
func fourSum(nums []int, target int) [][]int {
	sort.Ints(nums)
	res := make([][]int, 0)

	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}
		for j := i + 1; j < len(nums)-2; j++ {
			if j > i+1 && nums[j] == nums[j-1] {
				continue
			}
			sum := nums[i] + nums[j]
			left, right := j+1, len(nums)-1
			for left < right {
				if sum+nums[left]+nums[right] == target {
					res = append(res, []int{nums[i], nums[j], nums[left], nums[right]})
					left++
					right--
					for left < right && nums[left] == nums[left-1] {
						left++
					}
					for left < right && nums[right] == nums[right+1] {
						right--
					}
				} else if sum+nums[left]+nums[right] < target {
					left++
				} else {
					right--
				}
			}
		}
	}
	return res
}