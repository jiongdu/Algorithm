func spiralOrder(matrix [][]int) []int {
	if len(matrix) == 0 {
		return []int{}
	}
	result := make([]int, 0, len(matrix)*len(matrix[0]))
	up, down, left, right := 0, len(matrix)-1, 0, len(matrix[0])-1
	for {
		//上边行
		for i := left; i <= right; i++ {
			result = append(result, matrix[up][i])
		}
		up++
		if up > down {
			break
		}
		//右边列
		for j := up; j <= down; j++ {
			result = append(result, matrix[j][right])
		}
		right--
		if right < left {
			break
		}
		//下边行
		for i := right; i >= left; i-- {
			result = append(result, matrix[down][i])
		}
		down--
		if down < up {
			break
		}
		//左边列
		for j := down; j >= up; j-- {
			result = append(result, matrix[j][left])
		}
		left++
		if left > right {
			break
		}
	}
	return result
}