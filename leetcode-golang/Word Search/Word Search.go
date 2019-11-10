func exist(board [][]byte, word string) bool {
	if len(board) == 0 {
		return true
	}
	visited := make([][]bool, len(board))
	for i := 0; i < len(board); i++ {
		visited[i] = make([]bool, len(board[0]))
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if dfs(board, i, j, 0, visited, word) { //这里不能直接return dfs(...)，因为对于i,j很多种情况，这样的话只会是i=0,j=0的情况
				return true
			}
		}
	}
	return false
}

func dfs(board [][]byte, i, j int, index int, visited [][]bool, word string) bool {
	if index == len(word) {
		return true
	}
	if i < 0 || j < 0 || i >= len(board) || j >= len(board[0]) || visited[i][j] || board[i][j] != word[index] {
		return false
	}
	visited[i][j] = true
	res := dfs(board, i+1, j, index+1, visited, word) ||
		dfs(board, i-1, j, index+1, visited, word) ||
		dfs(board, i, j+1, index+1, visited, word) ||
		dfs(board, i, j-1, index+1, visited, word)
	visited[i][j] = false
	return res
}
