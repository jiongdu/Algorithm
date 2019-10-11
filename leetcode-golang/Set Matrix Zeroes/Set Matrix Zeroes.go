func setZeroes(matrix [][]int) {
	if len(matrix) == 0 {
		return
	}
	row, column := len(matrix), len(matrix[0])
	//去重
	rows := make(map[int]bool, 0)
	columns := make(map[int]bool, 0)

	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if matrix[i][j] == 0 {
				rows[i], columns[j] = true, true
				//columns[j] = true
			}
		}
	}
	for k, _ := range rows {
		for j := 0; j < column; j++ {
			matrix[k][j] = 0
		}
	}
	for k, _ := range columns {
		for i := 0; i < row; i++ {
			matrix[i][k] = 0
		}
	}
	return
}
