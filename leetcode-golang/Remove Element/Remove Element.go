package leetcode_remove_element

//使用两个指针，将值等于val的数组元素全部交换到数组末尾，返回不等于val的元素个数
func removeElement(nums []int, val int) int {
	// j指向最后一个不为val的位置
	// i指向第一个值为val的位置
	i, j := 0, len(nums)-1
	for {
		for i < len(nums) && nums[i] != val {
			i++
		}

		for j >= 0 && nums[j] == val {
			j--
		}

		if i >= j {
			break
		}

		nums[i], nums[j] = nums[j], nums[i]
	}

	return i
}
