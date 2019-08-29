/**
 * @param A: An integer array
 * @param k: A positive integer (k <= length(A))
 * @param target: An integer
 * @return: An integer
 */
 func kSum (A []int, k int, target int) int {
    // write your code here
    if len(A) == 0 {
        return 0
	}
	//dp
    //ksum[i][j][l]表示前j个元素里面取l个元素之和为i
    //ksum[0][j][0] =1(j:0~n)
    //ksum[i][j][l]=ksum[i][j-1][l]+ksum[i-A[i-1]][j-1][l-1]
    dp := make([][][]int, target+1)
    for m := 0; m <= target; m++ {
        dp[m] = make([][]int, len(A)+1)
        for n := 0; n <= len(A); n++ {
            dp[m][n] = make([]int, k+1)
        }
    }
    for j := 0; j <= len(A); j++ {
        dp[0][j][0] = 1
    }
    for i := 1; i <= target; i ++ {
        for j := 1; j <= len(A); j++ {
            for l := 1; l<=j && l<=k; l++ {
                dp[i][j][l] = dp[i][j - 1][l];
                if(i - A[j - 1] >= 0){
                    dp[i][j][l] += dp[i - A[j - 1]][j - 1][l - 1];
                }
            }
        }
    }
    return dp[target][len(A)][k]
}
