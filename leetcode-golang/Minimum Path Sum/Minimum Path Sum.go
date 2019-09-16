func minPathSum(grid [][]int) int {
	row := len(grid)
	if row == 0 {
		return 0
	}
	column := len(grid[0])
	for i := 0; i < row; i++ {
		if i >= 1 {
			grid[i][0] += grid[i-1][0]
		}
	}
	for j := 0; j < column; j++ {
		if j >= 1 {
			grid[0][j] += grid[0][j-1]
		}
	}
	for i := 1; i < row; i++ {
		for j := 1; j < column; j++ {
			grid[i][j] = min(grid[i-1][j], grid[i][j-1]) + grid[i][j]
		}
	}
	return grid[row-1][column-1]
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}