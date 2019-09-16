func largestRectangleArea(heights []int) int {
	//只需在局部峰值处，就行向前处理
	result := 0
	for i := 0; i < len(heights); i++ {
		if i+1 < len(heights) && heights[i] <= heights[i+1] {
			continue
		}
		localPeak := heights[i]
		for j := i; j >= 0; j-- {
			localPeak = min(localPeak, heights[j])
			area := (i - j + 1) * localPeak
			if area > result {
				result = area
			}
		}
	}
	return result
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}
