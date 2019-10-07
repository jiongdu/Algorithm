import "sort"

func permute(nums []int) [][]int {
	result := [][]int{}
	if len(nums) <= 0 {
		return result
	}
	sort.Ints(nums)
	start := 0
	permuteHelp(nums, start, &result)
	return result
}

func permuteHelp(nums []int, start int, result *[][]int) {
	if start == len(nums)-1 {
		t := make([]int, len(nums))
		copy(t, nums)
		*result = append(*result, t)
		//*result = append(*result, nums)	//这样就会变成所有子数组都是[1,2,3]
		return
	}
	for i := start; i < len(nums); i++ {
		nums[i], nums[start] = nums[start], nums[i]
		permuteHelp(nums, start+1, result)
		nums[i], nums[start] = nums[start], nums[i]
	}
	return
}


import "sort"

func permute(nums []int) [][]int {
	result := [][]int{}
	if len(nums) <= 0 {
		return result
	}
	sort.Ints(nums)
	start := 0
	permuteHelp(nums, start, &result)
	return result
}

func permuteHelp(nums []int, start int, result *[][]int) {
	if start == len(nums)-1 {
        // t := make([]int, len(nums))
        // copy(t, nums)
		//*result = append(*result, t)
        *result = append(*result, append([]int{}, nums...))		//深拷贝和浅拷贝的原因，这样写也可以
		return
	}
	//交换start和i，递归之后，然后交换回来
	for i := start; i < len(nums); i++ {
		nums[i], nums[start] = nums[start], nums[i]
		permuteHelp(nums, start+1, result)
		nums[i], nums[start] = nums[start], nums[i]
	}
	return
}