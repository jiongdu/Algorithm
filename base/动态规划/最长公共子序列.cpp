int longestCommonSubsequence(string A, string B){
	if(A.length()==0 || B.length()==0) return 0;
	int xlen = A.length();
	int ylen = B.length();
	vector<vector<int> > dp(xlen+1, vector<int>(ylen+1));
	for(int i=0;i<xlen;i++){
		for(int j=0;j<ylen;j++){
			dp[i][j]=0;
		}
	}
	for(int i=1;i<=xlen;i++){
		for(int j=1;j<xlen;j++){
			if(A[i-1]==B[i-1]){
				dp[i][j]=dp[i-1][j-1]+1;
			}else{
				dp[i][j]=std::max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[xlen][ylen];
}