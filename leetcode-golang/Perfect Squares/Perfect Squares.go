import "math"

func numSquares(n int) int {
	cache := make(map[int]int)
	cache[0] = 0
	return doNumSquares(n, cache)
}

func doNumSquares(n int, cache map[int]int) int {
	if found, ok := cache[n]; ok {
		return found
	}
	res := math.MaxInt32
	for i := 1; i*i <= n; i++ {
		target := n - i*i
		res = min(res, doNumSquares(target, cache)+1)
	}
	cache[n] = res
	return res
}