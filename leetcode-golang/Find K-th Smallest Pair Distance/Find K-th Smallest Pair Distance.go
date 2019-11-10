import "sort"

func smallestDistancePair(nums []int, k int) int {
	if len(nums) == 0 {
		return 0
	}
	sort.Ints(nums)
	n := len(nums)
	left, right := 0, nums[n-1]-num[0] //right为开始最大距离
	for left < right {
		mid := left + (right-left)/2 //中间距离
		cnt, start := 0, 0
		for i := 0; i < n; i++ {
			for start < n && nums[i]-nums[start] > mid {
				start++
			}
			cnt += (i - start)
		}
		if cnt < k {
			left = mid + 1
		} else {
			right = mid //有可能会超，在重复的数组中
		}
	}
	return right
}