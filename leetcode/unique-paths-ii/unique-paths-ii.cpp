/**************************************
* @author dujiong
* @date 2016.12.1
* @version V0.1
**************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(m==0 || obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1){
            return 0;
        }
        int dp[m][n];
        dp[0][0]=1;
        for(int i=1;i<m;i++){
			if(obstacleGrid[i][0]==0){
                dp[i][0]=1;
            }else{
                for(int j=i;j<m;j++){
                    dp[j][0]=0;
                }
                break;
            }
        }
        for(int k=1;k<n;k++){
            if(obstacleGrid[0][k]==0){
                dp[0][k]=1;
            }else{
                for(int j=k;j<n;j++){
                    dp[0][j]=0;
                }
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]!=1){
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];
                }else{
                    dp[i][j]=0;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
