import "math"

//这个方法太巧妙了
func increasingTriplet(nums []int) bool {
	m1, m2 := math.MaxInt32, math.MaxInt32
	for i := 0; i < len(nums); i++ {
		if m1 >= nums[i] {
			m1 = nums[i]
		} else if m2 >= nums[i] {
			m2 = nums[i]
		} else {
			return true
		}
	}
	return false
}