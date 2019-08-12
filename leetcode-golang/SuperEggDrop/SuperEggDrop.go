//K个鸡蛋在N层楼的情况下求解需要多少步;
//另一种思路是求K个鸡蛋在m步内可以测出多少层
//f(k,m)=f(k-1,m-1)+f(k,m-1)+1]
//f(m,k)=f(m-1,k)+f(m-1,k-1)+1  m>=N时结束
func superEggDrop(K int, N int) int {
    if K==0 {
        return 0
    }
    if K==1 {
       return N 
    }
    dp := make([][]int, N+2)
    for i:=0; i<len(dp); i++ {
        temp := make([]int, K+2)
        dp[i] = append(dp[i], temp...)
    }
    dp[0][0] = 0
    for i:=1; i<=N; i++ {
        dp[i][0] = 0
        for j := 1; j<=K; j++ {
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1]+1
            if dp[i][j]>=N {
                return i
            }
        }
    }
    return N
}