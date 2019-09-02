func majorityElement(nums []int) int {
	//这个方法很有意思，也就是majority element的个数比其余的和还多
	if len(nums) <= 0 {
		return 0
	}
	temp := nums[0]
	num := 1
	for i := 1; i < len(nums); i++ {
		if nums[i] == temp {
			num++
		} else {
			if num == 1 {
				temp = nums[i]
			} else {
				num--
			}
		}
	}
	return temp
	//对于空间复杂度并不友好的方法
	// m := make(map[int]int)
	// for i := 0; i < len(nums); i++ {
	//     m[nums[i]]++
	// }
	// for k, v := range m {
	//     if v > len(nums)/2 {
	//         return k
	//     }
	// }
	// return 0
}