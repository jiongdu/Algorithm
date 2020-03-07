func search(A []int, target int) bool {
	// write your code here
	left, right := 0, len(A)-1
	for left <= right {
		mid := left + (right-left)/2
		if A[mid] == target {
			return true
		} else if A[mid] < A[right] { //右边有序
			if A[mid] < target && target <= A[right] {
				left = mid + 1
			} else {
				right = mid - 1
			}
		} else if A[mid] > A[right] { //左边有序
			if A[left] <= target && target < A[mid] {
				right = mid - 1
			} else {
				left = mid + 1
			}
		} else {
			right--
		}
	}

	return false
}