/**
 * @param nums: A list of non negative integers
 * @return: A string
 */

import (
	"sort"
	"strconv"
	"strings"
)

type Number []int

func (nums Number) Len() int {
	return len(nums)
}

func (nums Number) Less(i, j int) bool {
	ret := strings.Compare(strconv.Itoa(nums[i])+strconv.Itoa(nums[j]), strconv.Itoa(nums[j])+strconv.Itoa(nums[i]))
	if ret > 0 {
		return true
	}
	return false
}

func (nums Number) Swap(i, j int) {
	nums[i], nums[j] = nums[j], nums[i]
}

func largestNumber(nums []int) string {
	var res string
	sort.Sort(Number(nums))
	for i := range nums {
		res += strconv.Itoa(nums[i])
	}
	if res[0] == '0' {
		return "0"
	}
	return res
}
