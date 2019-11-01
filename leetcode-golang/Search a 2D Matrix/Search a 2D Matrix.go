//核心，从右上角开始剥洋葱
func searchMatrix(matrix [][]int, target int) bool {
	if len(matrix) == 0 {
		return false
	}
	row, column := 0, len(matrix[0])-1
	for row < len(matrix) && column >= 0 {
		if matrix[row][column] == target {
			return true
		} else if matrix[row][column] < target {
			row++
		} else {
			column--
		}
	}
	return false
}
