import (
	"math"
	"sort"
)

func threeSumClosest(nums []int, target int) int {
	diff := math.MaxInt32
	res := 0
	sort.Ints(nums)
	for i := 0; i < len(nums)-2; i++ {
		left, right := i+1, len(nums)-1
		for left < right {
			sum := nums[left] + nums[right]
			if nums[i]+sum == target {
				return 0
			} else if nums[i]+sum < target {
				left++
			} else {
				right--
			}
			if int(math.Abs(float64(sum+nums[i]-target))) < diff {
				diff = int(math.Abs(float64(sum + nums[i] - target)))
				res = sum + nums[i]
			}
		}
	}
	return res
}