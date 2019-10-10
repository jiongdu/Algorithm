import "math"

//根据index来获取对应的string
func getStringOfExcelIndex(index int) string {
	result := ""
	if index == 0 {
		return result
	} else if index <= 26 {
		result += string(rune(index-1) + rune('A'))
	} else if index > 26 { //在这种计数下，最后一个字符为Z的情况下，正好被26整数，因此要特殊处理
		result += getStringOfExcelIndex((index-1)/26) + getStringOfExcelIndex(index-((index-1)/26)*26)
	}
	return result
}

// 根据string来获取对应的index，和上面根据index来获取对应的string相同的计数规则
func getIndexOfExcelString(s string) int {
	length := len(s)
	index := 0
	for i := 0; i < length; i++ {
		if i != length-1 { //最后一位取数字即可，其余位再进行运算的时候需要+1，，，AB
			index += (int(s[i]-'A') + 1) * int(math.Pow(26, float64(length-1-i)))
		} else {
			index += (int(s[i]-'A') + 1)
		}
	}
	return index
}