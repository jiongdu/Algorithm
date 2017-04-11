int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int xlen = A.length();
        int ylen = B.length();
        int maxlen = 0;
        int maxindex = 0;
        vector<vector<int> > dp(xlen, vector<int>(ylen));
        for(int k=0;k<xlen;k++){
            for(int j=0;j<ylen;j++){
                dp[k][j]=0;
            }
        }
        for(int i=0;i<xlen;i++){
            for(int j=0;j<ylen;j++){
                if(A[i]==B[j]){
                    if(i&&j){
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }
                    if(dp[i][j]>maxlen){
                        maxlen=dp[i][j];
                        maxindex=i+1-maxlen;
                    }
                }
            }
        }
        //string res = A.substr(maxindex, maxlen);
        //return res.length();
        return maxlen;
}