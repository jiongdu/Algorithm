/**************************************
* @author dujiong
* @date 2016.10.13
* @version V0.1
**************************************/

class Flood {
public:
    int floodFill(vector<vector<int> > map, int n, int m) {

        int dp[101][101]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]==1){
                    dp[i][j]=10000;
                    continue;
                }
                if(i==0&&j==0){
                    dp[i][j]=0;
                }else if(i==0&&map[i][j]==0){
                    dp[i][j]=dp[i][j-1]+1;
                }else if(j==0&&map[i][j]==0){
                    dp[i][j]=dp[i-1][j]+1;
                }else{
                    dp[i][j]=std::min(dp[i-1][j],dp[i][j-1])+1;
                }
            }
        }
        return dp[n-1][m-1];
    }
};