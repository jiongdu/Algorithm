package main

import (
	"fmt"
	"strconv"
)

//实现shell *的功能，返回字符串在模式串匹配的起始位置和长度
func match(str, reg *string, str_pos, pat_pos int, start, length int) bool {
	if pat_pos == len(*reg) {
		fmt.Println(strconv.Itoa(start) + " " + strconv.Itoa(length))
		return true
	}
	if str_pos == len(*str) && pat_pos != len(*reg) {
		return false
	}
	if (*reg)[pat_pos] != '*' {
		if (*reg)[pat_pos] == (*str)[str_pos] {
			return match(str, reg, str_pos+1, pat_pos+1, start, length+1) //转移到下一状态
		} else {
			return false
		}
	} else { //reg为*
		a := match(str, reg, str_pos, pat_pos+1, start, length)
		b := match(str, reg, str_pos+1, pat_pos, start, length+1)
		return a || b
	}
	return false
}

func main() {
	var reg, str string
	fmt.Scanln(&reg)
	fmt.Scanln(&str)
	if reg == "*" {
		for i := 0; i < len(str); i++ {
			for j := 1; i+j <= len(str); j++ {
				fmt.Println(strconv.Itoa(i) + " " + strconv.Itoa(j))
			}
		}
		return
	}
	var succ bool = false
	for i := 0; i < len(str); i++ {
		if match(&str, &reg, i, 0, i, 0) {
			succ = true
		}
	}
	if !succ {
		fmt.Println(strconv.Itoa(-1) + " " + strconv.Itoa(0))
	}
	return
}
