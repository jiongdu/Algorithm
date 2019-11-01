func trap(height []int) int {
	if len(height) <= 0 {
		return 0
	}
	left, right := 0, len(height)-1
	res := 0
	for left < right {
		//找到当前两边波峰之中小的，可以避免另一边有更小的，要来作为base
		currentMax := min(height[left], height[right])
		if currentMax == height[left] {
			left++
			//left行进中比currentMax小，都可以装雨水
			for left < right && height[left] < currentMax {
				res = res + (currentMax - height[left])
				left++
			}
		}
		if currentMax == height[right] {
			right--
			for left < right && height[right] < currentMax {
				res = res + (currentMax - height[right])
				right--
			}
		}
	}
	return res
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}