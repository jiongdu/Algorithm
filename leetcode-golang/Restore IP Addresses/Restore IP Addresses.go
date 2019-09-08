import (
	"strconv"
	"strings"
)

func restoreIpAddresses(s string) []string {
	res := make([]string, 0)
	//可以转数组地址，然后在函数中修改
	buildRes(&res, s, make([]string, 0), 0)
	return res
}

func buildRes(res *[]string, s string, str []string, index int) {
	//终止条件，str中分割了四个数，且index正好到len(s)末尾
	if len(str) == 4 {
		if index == len(s) {
			//str中的点分的每一部分用.连接
			*res = append(*res, strings.Join(str, "."))
		}
		return
	}
	//每一个，i<index+3：因为最多三位数
	for i := index; i < index+3 && i < len(s); i++ {
		candidate := s[index : i+1]
		if num, _ := strconv.Atoi(candidate); num > 255 {
			break
		}
		str = append(str, candidate)
		//递归地去看
		buildRes(res, s, str, i+1)
		//不要最后一位,str = str[0 : len(str) - 1]
		str = str[0 : len(str)-1]
		if candidate == "0" {
			break
		}
	}
}

//下面这个好理解些
//这类回溯法的时间复杂度:N!
func restoreIpAddresses(s string) []string {
	var validateArr []string
	//三个分段点，分成四段，要确保条件满足，数组的右边是开区间
	for i1 := 1; i1 <= len(s)-3 && i1 < 4; i1++ {
		for i2 := i1 + 1; i2 <= len(s)-2 && i2-i1 < 4; i2++ {
			for i3 := i2 + 1; i3 <= len(s)-1 && i3-i2 < 4; i3++ {
				// can't begin with "0"
				//每一段的第一个数字不能为0
				if (len(s[0:i1]) > 1 && s[0:i1][0:1] == "0") || (len(s[i1:i2]) > 1 && s[i1:i2][0:1] == "0") ||
					(len(s[i2:i3]) > 1 && s[i2:i3][0:1] == "0") || (len(s[i3:]) > 1 && s[i3:][0:1] == "0") {
					continue
				}
				intTmp1, _ := strconv.Atoi(s[0:i1])
				intTmp2, _ := strconv.Atoi(s[i1:i2])
				intTmp3, _ := strconv.Atoi(s[i2:i3])
				intTmp4, _ := strconv.Atoi(s[i3:])
				// fmt.Println(intTmp1, intTmp2, intTmp3, intTmp4)

				if intTmp1 < 256 && intTmp2 < 256 && intTmp3 < 256 && intTmp4 < 256 {
					validateArr = append(validateArr, s[0:i1]+"."+s[i1:i2]+"."+s[i2:i3]+"."+s[i3:])
				}
			}
		}
	}
	return validateArr
}