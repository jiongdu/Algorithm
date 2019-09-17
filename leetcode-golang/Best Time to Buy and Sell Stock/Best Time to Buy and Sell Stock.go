func maxProfit(prices []int) int {
	if len(prices) <= 1 {
		return 0
	}
	result := 0
	local := prices[0]
	for i := 1; i < len(prices); i++ {
		if prices[i]-local > result {
			result = prices[i] - local
		}
		if prices[i] < local {
			local = prices[i]
		}
	}
	return result
}