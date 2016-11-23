/**************************************
* @author dujiong
* @date 2016.11.23
* @version V0.1
**************************************/

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        int m = grid.size();			//m: 行
        int n = grid[0].size();			//n: 列
        int dp[m][n];
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++){
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int j=1;j<n;j++){
            dp[0][j]=dp[0][j-1]+grid[0][j];
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=std::min(dp[i][j-1], dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
