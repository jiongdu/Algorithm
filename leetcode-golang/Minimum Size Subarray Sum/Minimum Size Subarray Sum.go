import "math"

func min(i, j int) int {
	if i < j {
		return i
	}
	return j
}

func minSubArrayLen(s int, nums []int) int {
	var res int = math.MaxInt32
	for i := 0; i < len(nums); i++ {
		localSum := 0
		for j := i; j < len(nums); j++ {
			localSum += nums[j]
			if localSum >= s {
				res = min(res, j-i+1)
				break
			}
		}
	}
	if res == math.MaxInt32 {
		return 0
	}
	return res
}

func minSubArrayLen(s int, nums []int) int {
	res := math.MaxInt32
	left, right := 0, 0
	localSum := 0
	for right < len(nums) {
		//右指针移动
		for right < len(nums) && localSum < s {
			localSum += nums[right]
			right++
		}
		//左指针移动
		for localSum >= s {
			res = min(res, right-left)
			localSum = localSum - nums[left]
			left++
		}
	}
	if res == math.MaxInt32 {
		return 0
	}
	return res
}