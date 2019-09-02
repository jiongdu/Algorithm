import "math"

func myAtoi(str string) int {
	res, sign, len, idx := 0, 1, len(str), 0

	// Skip leading spaces
	for idx < len && (str[idx] == ' ' || str[idx] == '\t') {
		idx++
	}

	// +/- Sign
	if idx < len {
		if str[idx] == '+' {
			sign = 1
			idx++
		} else if str[idx] == '-' {
			sign = -1
			idx++
		}
	}

	// Numbers,不用去管其他那些字符，不满足直接就不走for循环，没有赋值
	for idx < len && str[idx] >= '0' && str[idx] <= '9' {
		res = res*10 + int(str[idx]) - '0'
		if sign*res > math.MaxInt32 {
			return math.MaxInt32
		} else if sign*res < math.MinInt32 {
			return math.MinInt32
		}
		idx++
	}

	return res * sign
}