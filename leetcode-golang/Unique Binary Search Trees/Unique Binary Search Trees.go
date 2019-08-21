func numTrees(n int) int {
    dp := make([]int, n+1)
    dp[0] = 1
    dp[1] = 1
    for i := 2; i<=n; i++ {
        for j := 0; j<i; j++ {
            dp[i] += dp[j] * dp[i-j-1]
        }
    }
    return dp[n]
}

/*
dp[3] =  dp[0] * dp[2]　　　(1为根的情况)

　　　　+ dp[1] * dp[1]　　  (2为根的情况)

 　　　  + dp[2] * dp[0]　　  (3为根的情况)
*/