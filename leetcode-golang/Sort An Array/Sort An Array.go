//各种排序算法汇总

//冒泡、插入、选择排序

//冒泡
func sortArray(nums []int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		for j := 0; j < length-i-1; j++ {
			if nums[j] > nums[j+1] {
				nums[j], nums[j+1] = nums[j+1], nums[j]
			}
		}
	}
	return nums
}

//插入
func sortArray(nums []int) []int {
	length := len(nums)
	for i := 1; i < length; i++ {
		tmp := nums[i]
		j := i - 1
		for ; j >= 0 && nums[j] > tmp; j-- {
			nums[j+1] = nums[j]
		}
		nums[j+1] = tmp
	}
	return nums
}

//选择
func sortArray(nums []int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		min := i //需要从i开始，比如1 2 3 5，i现在等于1，如果从i=2开始（即3），那么后面序列最小值为3，和2交换，这不对，应该认为i也是属于未排序的序列
		for j := i; j < length; j++ {
			if nums[j] < nums[min] {
				min = j
			}
		}
		nums[min], nums[i] = nums[i], nums[min]
	}
	return nums
}

//归并、快排
//归并
func sortArray(nums []int) []int {
	if len(nums) < 2 { //递归的结束条件
		return nums
	}
	mid := len(nums) / 2
	left := sortArray(nums[0:mid])
	right := sortArray(nums[mid:])
	result := merge(left, right)
	return result
}

func merge(left, right []int) []int {
	result := make([]int, 0)
	m, n := 0, 0
	for m < len(left) && n < len(right) {
		if left[m] < right[n] {
			result = append(result, left[m]) //不能使用left[m++]这种c++的方法
			m++
		} else {
			result = append(result, right[n])
			n++
		}
	}
	result = append(result, left[m:]...)
	result = append(result, right[n:]...)
	return result
}

//快排
func sortArray(nums []int) []int {
	if len(nums) < 2 {
		return nums
	}
	quickSortArray(nums, 0, len(nums)-1)
	return nums
}

func quickSortArray(nums []int, left, right int) {
	if left >= right {
		return
	}
	j := partition(nums, left, right)
	quickSortArray(nums, left, j-1)
	quickSortArray(nums, j+1, right)
}

func partition(nums []int, left, right int) int {
	base := nums[left]
	for left < right {
		for left < right && nums[right] >= base {
			right--
		}
		nums[left] = nums[right]
		for left < right && nums[left] < base {
			left++
		}
		nums[right] = nums[left]
	}
	nums[left] = base
	return left
}

//堆排序
func sortArray(nums []int) []int {
	n := len(nums)
	for i := n/2 - 1; i >= 0; i-- {
		down(h, i, n)
	}
}