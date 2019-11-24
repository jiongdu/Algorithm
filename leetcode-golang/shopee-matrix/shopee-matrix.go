package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

func main() {

	var length int
	fmt.Scanln(&length)
	vec := make([][]int, length)
	for i := 0; i < length; i++ {
		vec[i] = make([]int, length)
	}
	vis := make([][]int, length)
	for i := 0; i < length; i++ {
		vis[i] = make([]int, length)
	}
	scan := bufio.NewScanner(os.Stdin)
	for i := 0; i < length; i++ {
		var str string
		if scan.Scan() {
			str = scan.Text()
		}
		nums := strings.Fields(str)
		for j := 0; j < len(nums); j++ {
			num, _ := strconv.Atoi(nums[j])
			vec[i][j] = num
		}
	}

	for i := 0; i < length; i++ {
		for j := 0; j < length; j++ {
			if vec[i][j] == 0 {
				n := j
				for m := i; m < length; m++ {
					for ; n < length; n++ {
						if vec[m][n] == 1 {
							vis[i][j] += (abs(m-i) + abs(n-j))
							// fmt.Println("vis[i][j] is ", vis[i][j])
						}
					}
					n = 0
				}
			} else {
				n := j
				vis[i][j] = math.MaxInt32
				for m := i; m < length; m++ {
					for ; n < length; n++ {
						if vec[m][n] == 0 {
							vis[m][n] += (abs(m-i) + abs(n-j))
						}
					}
					n = 0
				}
			}
		}
	}
	res := math.MaxInt32
	for i := 0; i < length; i++ {
		for j := 0; j < length; j++ {
			res = min(res, vis[i][j])
		}
	}
	if res == math.MaxInt32 {
		fmt.Println(-1)
	}
	fmt.Println(res)
	return
}

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func abs(i int) int {
	if i > 0 {
		return i
	}
	return 0 - i
}
