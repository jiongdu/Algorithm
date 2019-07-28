//删除重复的数字，只保留一次
func removeDuplicates(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	result := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1] {
			nums[result] = nums[i]
			result ++
		}
	}
	return result
}

//删除重复的数字，保留两次
//需要从left向right比较，不然会覆盖原来的元素，造成错误
func removeDuplicates(nums []int) int {
    if len(nums) <= 2 {
        return len(nums)
    }
    result := 0
    for i := 0; i < len(nums)-2; i++ {
        if nums[i] == nums[i+1] && nums[i] == nums[i+2] {
            continue
        }
        nums[result] = nums[i]
        result++
    }
    nums = append(nums[:result], nums[len(nums)-2:]...)
    result += 2
    return result
}