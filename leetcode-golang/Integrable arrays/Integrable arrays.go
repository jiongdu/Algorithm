//最长可整合子数组的长度
package main

import (
	"fmt"
	"sort"
)

func main() {
	var n int
	fmt.Scanln(&n)
	if n == 0 || n == 1 {
		fmt.Println(n)
		return
	}
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d" & a[i])
	}

	sort.Ints(a)
	result, local := 0, 1
	temp := a[0]
	for i := 1; i < n; i++ {
		if a[i] == temp {
			continue
		}
		if a[i]-temp == 1 {
			local++
			temp = a[i]
			if result < local {
				result = local
			}
			continue
		}
		local = 1
		temp = a[i]
	}
	return result
}
