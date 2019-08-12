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

//如果数组为有序的，且返回值最小为1  的场景，二分查找
func twoSum(numbers []int, target int) []int {
    if len(numbers) <= 1 {
        return []int{}
    }
    left := 0
    right := len(numbers) - 1
    for left < right {
        if numbers[left] + numbers[right] == target {
            return []int{left+1, right+1}
        } else if numbers[left] + numbers[right] < target {
            left++
        } else {
            right--
        }
    }
    return []int{}
}
