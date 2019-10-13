//DFS
func longestIncreasingPath(matrix [][]int) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		return 0
	}
	row, column := len(matrix), len(matrix[0])
	dp := make([][]int, row, row)
	for i := range dp {
		dp[i] = make([]int, column, column)
	}
	res := 0
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			res = max(res, dfs(matrix, dp, i, j))
		}
	}
	return res
}

func dfs(matrix [][]int, dp [][]int, i, j int) int {
	if dp[i][j] > 0 { //从该点出发可以递增的路径长度，据为己用，免得重复计算
		return dp[i][j]
	}
	dx := []int{-1, 1, 0, 0}
	dy := []int{0, 0, 1, -1}

	for k := 0; k < 4; k++ {
		x, y := i+dx[k], j+dy[k]
		if x >= 0 && y >= 0 && x < len(matrix) && y < len(matrix[0]) && matrix[x][y] < matrix[i][j] {
			dp[i][j] = max(dp[i][j], dfs(matrix, dp, x, y))
		}
	}
	dp[i][j]++
	return dp[i][j]
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}