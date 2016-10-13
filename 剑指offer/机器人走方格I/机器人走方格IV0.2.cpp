/**************************************
* @author dujiong
* @date 2016.10.13
* @version V0.2
**************************************/

class Robot {
public:
    int countWays(int x, int y) {

        int dp[13][13]={0};
        dp[0][0]=0;
        for(int i=1;i<y;i++){
            dp[0][i]=1;
        }
        for(int j=1;j<x;j++){
            dp[j][0]=1;
        }
        for(int i=1;i<x;i++){
            for(int j=1;j<y;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[x-1][y-1];
    }
};