func maximalRectangle(matrix [][]byte) int {
	length := len(matrix)
	if length == 0 {
		return 0
	}
	column := len(matrix[0])
	height := make([]int, column, column)
	res := 0
	for i := 0; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == '1' {
				if i == 0 {
					height[j] = 1
				} else {
					height[j] = height[j] + 1
				}
			} else if matrix[i][j] == '0' {
				height[j] = 0
			}
		}
		res = max(res, largestRectangleArea(height))
	}
	return res
}

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

func max(i, j int) int {
	if i < j {
		return j
	}
	return i
}
