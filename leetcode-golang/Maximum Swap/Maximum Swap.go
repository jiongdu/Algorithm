import "strconv"

//低位的大数和高位的小数交换
//数字从0到9，桶排序的思想
func maximumSwap(num int) int {
	numByte := []byte(strconv.Itoa(num))
	array := make([]int, 10)
	for i, b := range numByte {
		array[b-'0'] = i
	}

	for i := 0; i < len(numByte); i++ {
		for j := 9; j > int(numByte[i]-'0'); j-- { //要找比当前大的
			if array[j] <= i {
				continue
			}
			numByte[array[j]], numByte[i] = numByte[i], numByte[array[j]]
			result, _ := strconv.Atoi(string(numByte))
			return result
		}
	}
	return num
}