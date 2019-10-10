dp[i][j] = dp[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');		//ok
dp[i][j] = dp[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 time;		//ok
dp[i][j] = dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' 
and the pattern repeats for at least 1 time.

func isMatch(s string, p string) bool {
	m, n := len(s), len(p)
	dp := make([][]bool, m+1)
	for i := 0; i < m+1; i++ {
		dp[i] = make([]bool, n+1)
	}
	dp[0][0] = true
	for j := 1; j <= n; j++ {
		if p[j-1] == '.' {
			dp[0][j] = false
		} else if p[j-1] == '*' {
			dp[0][j] = dp[0][j-1] || (j >= 2 && dp[0][j-2]) //key, dp[0][j-1]代表*为0个字符，dp[0][j-2]代表*为上个字符的0个
		} else {
			dp[0][j] = false
		}
	}

	for i := 1; i <= m; i++ {
		for j := 1; j <= n; j++ {
			if p[j-1] == '.' { //'.'只能代表一个字符
				dp[i][j] = dp[i-1][j-1]
			} else if p[j-1] == '*' { //key, (j >= 2 && dp[i][j-2])：匹配0个元素，即消除p[j-2]；；；(dp[i][j-1])：前面元素出现1次
				dp[i][j] = (j >= 2 && dp[i][j-2]) || (dp[i][j-1]) ||
					(dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'))		//已经出现过一次，aa, a*可用尝试，s[i-1] == p[j-2] || p[j-2] == '.')确保可用重复， dp[i-1][j]重复一次ok
			} else {
				dp[i][j] = (s[i-1] == p[j-1]) && (dp[i-1][j-1])
			}
		}
	}
	return dp[m][n]
}