/**************************************
* @author dujiong
* @date 2016.10.13
* @version V0.1
**************************************/

class Robot {
public:
    int countWays(vector<vector<int> > map, int x, int y) {
        int dp[50][50]={0};
        int i=0;
        while(i<y){
            if(map[0][i]==1){
                dp[0][i]=1;
                i++;
            }else{
                for(int k=i;k<y;k++){
                    dp[0][k]=0;
                }
                break;
            }
        }
        int j=0;
        while(j<x){
            if(map[j][0]==1){
                dp[j][0]=1;
                j++;
            }else{
                for(int k=j;k<x;k++){
                    dp[k][0]=0;
                }
                break;
            }
        }
        for(int m=1;m<x;m++){
            for(int n=1;n<y;n++){
                if(map[m][n]==1){
                    dp[m][n]=dp[m-1][n]+dp[m][n-1];
                }else{
                    dp[m][n]=0;
                }
            }
        }
        return dp[x-1][y-1]%1000000007;
        
    }
};