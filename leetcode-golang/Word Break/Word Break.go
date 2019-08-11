// 动态规划表达式
// dp[i] = dp[j] + (dp[j:i] in wordDict) for 0<j<i

func wordBreak(s string, wordDict []string) bool {
    result := make([]bool, len(s)+1)
    result[0] = true
    for i := 1; i <= len(s); i++ {
        for j := 0; j < i; j++ {
            if result[j] && contains(wordDict, s[j:i]) {
                result[i] = true
                break
            }
        }
    }
    return result[len(s)]
}

func contains(list []string, word string) bool {
    for _, v := range list {
        if word == v {
            return true
        }
    }
    return false
}