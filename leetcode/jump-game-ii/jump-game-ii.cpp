/**************************************
* @author dujiong
* @date 2016.11.24
* @version V0.1
**************************************/

class Solution {
public:
    int jump(int A[], int n) {
        if(n==0 || n==1) return 0;
        vector<int> dp(n, 65535);
        dp[0]=0;
        for(int i=0;i<n-1;++i){
            for(int j=i+1;j<=A[i]+i && j<n;++j){
                dp[j]=std::min(dp[i]+1,dp[j]);
            }
            if(dp[n-1]!=65535){
                return dp[n-1];
            }
        }
        return -1;
    }
};
