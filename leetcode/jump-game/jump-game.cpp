/**************************************
* @author dujiong
* @date 2016.11.23
* @version V0.1
**************************************/

class Solution {
public:
    bool canJump(int A[], int n) {
        if(n==0 || n==1){
            return true;
        }
        vector<bool> dp(n, false);
        dp[0]=true;
        
        for(int i=0;i<n-1;i++){
            if(dp[i]==true){
                int temp = i+A[i];
            	for(int j=1;j<=temp;j++){
                	dp[j]=true;
            	}
            } 
            if(dp[n-1]==true){
				return true;
            }
        }
        return false;
    }
};
