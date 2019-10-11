func solve(board [][]byte) {
	if len(board) == 0 || len(board[0]) == 0 || len(board) <= 2 || len(board[0]) <= 2 {
		return
	}
	for i := 0; i < len(board); i++ {
		visitNeighbors(board, i, 0)               //最左边第0列开始，dfs的，不仅仅是第0列
		visitNeighbors(board, i, len(board[0])-1) //最右边第len(board[0])-1列开始，dfs的，不仅仅是第len(board[0])-1列
	}
	for j := 0; j < len(board[0]); j++ {
		visitNeighbors(board, 0, j)            //最上面第0行
		visitNeighbors(board, len(board)-1, j) //最下面第len(board)-1列
	}
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if board[i][j] == 'O' {
				board[i][j] = 'X'
			} else if board[i][j] == '-' {
				board[i][j] = 'O'
			}
		}
	}
}

func visitNeighbors(board [][]byte, i, j int) {
	if i < 0 || j < 0 || i > len(board)-1 || j > len(board[0])-1 || board[i][j] != 'O' {
		return
	}
	//replace andy unbounded 'O' with '-'
	board[i][j] = '-'
	visitNeighbors(board, i-1, j)
	visitNeighbors(board, i+1, j)
	visitNeighbors(board, i, j-1)
	visitNeighbors(board, i, j+1)
	return
}