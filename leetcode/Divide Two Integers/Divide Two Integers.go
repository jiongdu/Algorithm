import "math"

func divide(dividend int, divisor int) int {
	quotient := 0
	sign := 1

	//the abs minInt32 is equal maxInt32+1, so if the divisor = -1, will overflow
	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}

	//capture the sign
	if divisor < 0 && dividend < 0 {
		divisor = -divisor
		dividend = -dividend

	} else if divisor < 0 {
		divisor = -divisor
		sign = -1

	} else if dividend < 0 {
		dividend = -dividend
		sign = -1

	}

	// divide some part to approach the answer
	// 除法的核心代码
	for dividend >= divisor {
		multiple := divisor
		for i := 0; dividend >= multiple; i++ {
			dividend -= multiple
			quotient += 1 << uint(i)
			multiple <<= 1 //乘以2
		}
	}
	//这样看得更明白些
	// for dividend >= divisor { //每次2倍去试探，可以往下；如果2倍大了，就回，multiple := divisor，multiple去变
	// 	multiple := divisor
	// 	for i := 0; multiple <= dividend; i++ {
	// 		dividend -= multiple
	// 		quotient += int(math.Pow(2, float64(i)))
	// 		multiple = multiple * 2
	// 	}
	// }

	if sign == -1 {
		return -quotient
	}

	return quotient
}