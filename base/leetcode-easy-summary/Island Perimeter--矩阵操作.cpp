/*
 * leetcode: 463
 */
int islandPerimeter(vector<vector<int>>& grid) {
	if(grid.empty()) return 0;
	int rows = grid.size();
	int columns = grid[0].size();
	int res = 0;
	for(int i=0;i<rows;++i){
		for(int j=0;j<columns;++j){
			if(grid[i][j]==0) continue;
			if(j==0 || grid[i][j-1]==0) res++;      
			if(i==rows-1 || grid[i+1][j]==0) res++;
			if(j==columns-1 || grid[i][j+1]==0) res++;
			if(i==0 || grid[i-1][j]==0) res++;
		}
	}
	return res;
}