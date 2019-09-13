var visited [][]int

func maxAreaOfIsland(grid [][]int) int {
	count := 0
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return count
	}
	row, col := len(grid), len(grid[0])
	//单独拎出一个数组来保存visited信息
	visited = make([][]int, row)
	for i := 0; i < row; i++ {
		visited[i] = make([]int, col)
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if grid[i][j] == 1 && visited[i][j] == 0 {
				area := helper(grid, i, j)
				if area > count {
					count = area
				}
			}
		}
	}
	return count
}

func helper(grid [][]int, i, j int) int {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || grid[i][j] == 0 || visited[i][j] != 0 {
		return 0
	}
	area := 1
	visited[i][j] = 1
	area += helper(grid, i, j-1)
	area += helper(grid, i, j+1)
	area += helper(grid, i-1, j)
	area += helper(grid, i+1, j)
	return area
}