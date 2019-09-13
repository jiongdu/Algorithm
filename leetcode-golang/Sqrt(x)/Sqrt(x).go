//最朴实的算法
func mySqrt(x int) int {
	INT_MAX := int(^uint32(0) >> 1)
	for i := 0; i < INT_MAX; i++ {
		if i*i <= x && (i+1)*(i+1) > x {
			return i
		}
	}
	return 0
}

//二分法，这个确实需要掌握二分法
func mySqrt(x int) int {
	if x <= 1 {
		return x
	}
	left, right := 0, x
	for left < right {
		mid := left + (right-left)/2
		if mid*mid == x {
			return mid
		} else if mid*mid < x {
			left = mid + 1
		} else {
			right = mid //mid已经确实平方后比right大，但是mid-1并没有比较，因此还是将right设置成mid，
		}
	}
	return right - 1
}