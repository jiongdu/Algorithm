func isMatch(s string, p string) bool {
    m, n := len(s), len(p)
    dp := make([][]bool, m+1)
    for i := 0; i < m+1; i++ {
        dp[i] = make([]bool, n+1)
    }
    dp[0][0] = true
    for j := 1; j < n+1; j++ {
        if p[j-1] == '*' {
            dp[0][j] = dp[0][j-1]
        }
    }
    for i := 1; i < m+1; i++ {
        for j := 1; j < n+1; j++ {
            if p[j-1] == '*' {
                dp[i][j] = dp[i-1][j] || dp[i][j-1]
            } else if p[j-1] == '?' {
                dp[i][j] = dp[i-1][j-1]
            } else {
                if p[j-1] == s[i-1] {
                    dp[i][j] = dp[i-1][j-1]
                }
            }
        }
    }
    return dp[m][n]
}