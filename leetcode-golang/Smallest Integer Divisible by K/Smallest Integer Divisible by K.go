func smallestRepunitDivByK(K int) int {
	if K%2 == 0 || K%5 == 0 {
		return -1
	}
	value := 0
	//https://www.cnblogs.com/zywscq/p/10699120.html
	for i := 1; i <= K+1; i++ { // 枚举停止，因为K的余数不包括0的话有K-1个,我们算了K个,K个里面没有0的话,里面必然至少有两个相等的
		value = (10*value + 1) % K
		if value == 0 {
			return i
		}
	}
	return -1
}

// func smallestRepunitDivByK(K int) int {
// 	value, length := 0, 0
// 	for i := 0; i < int(math.Pow(10, 6)); i++ {
// 		value = (10*value + 1) % K
// 		length++
// 		if value == 0 {
// 			return length
// 		}
// 	}
// 	return -1
// }