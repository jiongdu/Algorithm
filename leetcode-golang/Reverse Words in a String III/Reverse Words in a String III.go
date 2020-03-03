import (
	"fmt"
	"strings"
)

func reverseWords(s string) string {
	//不能用string，因为string是不可变的，所以不能赋值
	bs := []byte(s)
	left := 0
	for i, b := range bs {
		if b == ' ' {
			reverse(&bs, left, i-1)
			left = i + 1
		}
	}
	reverse(&bs, left, len(bs)-1)
	return string(bs)
}

func reverse(src *[]byte, from int, to int) {
	for from < to {
		(*src)[from], (*src)[to] = (*src)[to], (*src)[from]
		from++
		to--
	}
}

//不能用string，可以不用*[]byte，直接使用[]byte，因为slice是引用类型
func reverseWords(s string) string {
	//不能用string，因为string是不可变的，所以不能赋值
	bs := []byte(s)
	left := 0
	for i, b := range bs {
		if b == ' ' {
			reverse(bs, left, i-1)
			left = i + 1
		}
	}
	reverse(bs, left, len(bs)-1)
	return string(bs)
}

func reverse(src []byte, from int, to int) {
	for from < to {
		src[from], src[to] = src[to], src[from]
		from++
		to--
	}
}

//使用string.Builder可以提升性能
func reverseWords(s string) string {
	if len(s) == 0 {
		return ""
	}
	strSlice := strings.Fields(s)
	if len(strSlice) == 0 {
		return ""
	}
	for i := 0; i < len(strSlice)/2; i++ {
		strSlice[i], strSlice[len(strSlice)-1-i] = strSlice[len(strSlice)-1-i], strSlice[i]
	}
	var b strings.Builder
	for i := 0; i < len(strSlice)-1; i++ {
		fmt.Fprint(&b, strSlice[i])
		fmt.Fprint(&b, " ")
	}
	fmt.Fprint(&b, strSlice[len(strSlice)-1])
	return b.String()
}
