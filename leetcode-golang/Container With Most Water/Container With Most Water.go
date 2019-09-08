func maxArea(height []int) int {
	i, j := 0, len(height)-1
	ret := 0
	for i < j {
		ret = max(ret, min(height[i], height[j])*(j-i))
		if height[i] < height[j] {
			i++
		} else {
			j--
		}
	}
    return ret
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}