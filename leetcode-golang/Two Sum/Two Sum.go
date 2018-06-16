package leetcode_two_sum

func twoSum(nums []int, target int) []int {
	lookup := make(map[int]int)
	for i, num := range nums {
		if j, ok := lookup[target-num]; ok {
			return []int{i, j}
		}
		lookup[nums[i]] = i
	}
	return nil
}
