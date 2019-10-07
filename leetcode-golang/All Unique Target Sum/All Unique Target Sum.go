package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n, k int
	fmt.Scanln(&n, &k)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	var arr []int
	for i := 0; i < n && scanner.Scan(); i++ {
		num, _ := strconv.Atoi(scanner.Text())
		arr = append(arr, num)
	}

	print_pair(arr, k)
}

func print_pair(numbers []int, target int) {
	if numbers == nil || len(numbers) == 0 {
		return
	}
	left := 0
	right := len(numbers) - 1
	for left < right {
		if numbers[left]+numbers[right] == target {
			if left == 0 || numbers[left-1] != numbers[left] { //unique
				fmt.Printf("%d %d\n", numbers[left], numbers[right])
			}
			left++
			right--
		} else if numbers[left]+numbers[right] < target {
			left++
		} else {
			right--
		}
	}
}
