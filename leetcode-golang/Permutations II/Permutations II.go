import "sort"

func permuteUnique(nums []int) [][]int {
	if len(nums) == 0 {
		return [][]int{}
	}
	res := [][]int{}
	sort.Ints(nums)
	permuteHelp(nums, 0, &res)
	return res
}

func permuteHelp(nums []int, start int, res *[][]int) {
	if start == len(nums)-1 {
		*res = append(*res, append([]int{}, nums...))
		return
	}
	freq := [20]bool{} //有负数
	for i := start; i < len(nums); i++ {
		if freq[nums[i]+10] {
			continue
		}
		nums[start], nums[i] = nums[i], nums[start]
		permuteHelp(nums, start+1, res)
		nums[start], nums[i] = nums[i], nums[start]
		freq[nums[i]+10] = true
	}
	return
}