func containsDuplicate(nums []int) bool {
	m := make(map[int]bool)
	for _, value := range nums {
		if _, ok := m[value]; ok {
			return true
		} else {
			m[value] = true
		}
	}
	return false
	// c := make(chan bool)
	// go func() {
	// 	sort.Slice(nums, func(x, y int) bool {
	// 		if nums[x] == nums[y] {
	// 			c <- true
	// return false
	// 		}
	// 		return nums[x] < nums[y]
	// 	})
	// 	c <- false
	// }()
	// return <-c
}