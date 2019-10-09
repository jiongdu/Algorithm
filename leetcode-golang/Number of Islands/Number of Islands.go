func numIslands(grid [][]byte) int {
	count := 0
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return count
	}
	row, col := len(grid), len(grid[0])
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if string(grid[i][j]) == "1" {
				helper(grid, i, j)
				count++
			}
		}
	}
	return count
}

func helper(grid [][]byte, i, j int) {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || string(grid[i][j]) != "1" {
		return
	}
	grid[i][j] = byte('#')
	helper(grid, i-1, j)
	helper(grid, i+1, j)
	helper(grid, i, j-1)
	helper(grid, i, j+1)
}

//plan B
//不修改原来的grid数组，新开一个visit数组
var visited [][]int

func numIslands(grid [][]byte) int {
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
			if string(grid[i][j]) == "1" && visited[i][j] == 0 {
				helper(grid, i, j)
				count++
			}
		}
	}
	return count
}

func helper(grid [][]byte, i, j int) {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || string(grid[i][j]) == "0" || visited[i][j] != 0 {
		return
	}
	visited[i][j] = 1
	helper(grid, i, j-1)
	helper(grid, i, j+1)
	helper(grid, i-1, j)
	helper(grid, i+1, j)
}

//plan C
func numIslands(grid [][]byte) int {
	count := 0
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return count
	}
	row, col := len(grid), len(grid[0])
	//单独拎出一个数组来保存visited信息
	visited := make([][]int, row)
	for i := 0; i < row; i++ {
		visited[i] = make([]int, col)
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if string(grid[i][j]) == "1" && visited[i][j] == 0 {
				helper(grid, i, j, &visited)
				count++
			}
		}
	}
	return count
}

//visited传递指针
func helper(grid [][]byte, i, j int, visited *[][]int) {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || string(grid[i][j]) == "0" || (*visited)[i][j] != 0 {
		return
	}
	(*visited)[i][j] = 1
	helper(grid, i, j-1, visited)
	helper(grid, i, j+1, visited)
	helper(grid, i-1, j, visited)
	helper(grid, i+1, j, visited)
}

//plan D
//var visited [][]int

func numIslands(grid [][]byte) int {
	count := 0
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return count
	}
	row, col := len(grid), len(grid[0])
	//单独拎出一个数组来保存visited信息
	//make返回的是指针？还是说slice有特殊的地方
	visited := make([][]int, row)
	for i := 0; i < row; i++ {
		visited[i] = make([]int, col)
	}
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if string(grid[i][j]) == "1" && visited[i][j] == 0 {
				helper(grid, i, j, visited)
				count++
			}
		}
	}
	return count
}

//visited传值，不传指针
func helper(grid [][]byte, i, j int, visited [][]int) {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || string(grid[i][j]) == "0" || visited[i][j] != 0 {
		return
	}
	visited[i][j] = 1
	helper(grid, i, j-1, visited)
	helper(grid, i, j+1, visited)
	helper(grid, i-1, j, visited)
	helper(grid, i+1, j, visited)
}

//自己写的可以ac版本
//假设可以修改原数组
func numIslands(grid [][]byte) int {
	count := 0
	if len(grid) == 0 {
		return count
	}
	row, col := len(grid), len(grid[0])
	for i := 0; i < row; i++ {
		for j := 0; j < col; j++ {
			if helper(grid, i, j) == true {
				count++
			}
		}
	}
	return count
}

func helper(grid [][]byte, i, j int) bool {
	row, col := len(grid), len(grid[0])
	if i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1' {
		return false
	}
	grid[i][j] = '#'
	helper(grid, i+1, j)
	helper(grid, i-1, j)
	helper(grid, i, j-1)
	helper(grid, i, j+1)
	return true
}