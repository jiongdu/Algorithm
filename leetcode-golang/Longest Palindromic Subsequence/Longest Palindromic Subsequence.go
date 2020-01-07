func longestPalindromeSubseq(s string) int {
	dp := make([][]int, len(s), len(s))
	for i := 0; i < len(s); i++ {
		dp[i] = make([]int, len(s), len(s))
	}

	for i := len(s) - 1; i >= 0; i-- {
		dp[i][i] = 1
		for j := i + 1; j < len(s); j++ {
			if s[i] == s[j] {
				dp[i][j] = dp[i+1][j-1] + 2
			} else {
				dp[i][j] = max(dp[i+1][j], dp[i][j-1])
			}
		}
	}
	return dp[0][len(s)-1]
}

func max(i, j int) int {
	if i > j {
		return i
	}
	return j
}

//按照原来的方法，这样能通过45%的case，还不理解
// func longestPalindromeSubseq(s string) int {
// 	if len(s) == 0 {
// 		return 0
// 	}
// 	dp := make([][]int, len(s), len(s))
// 	for i := 0; i < len(s); i++ {
// 		dp[i] = make([]int, len(s), len(s))
// 	}

// 	maxLen := 1
// 	for i := 0; i < len(s); i++ {
// 		dp[i][i] = 1
// 		for j := 0; j < i; j++ {
// 			if s[i] == s[j] {
// 				if i-j < 2 {
// 					dp[j][i] = 2
// 				} else {
// 					dp[j][i] = dp[j+1][i-1] + 2
// 				}
// 			} else {
// 				dp[j][i] = max(dp[j+1][i-1], max(dp[j+1][i], dp[j][i-1]))
// 			}
// 			if dp[j][i] > maxLen {
// 				maxLen = dp[j][i]
// 			}
// 		}
// 	}
// 	return maxLen
// }