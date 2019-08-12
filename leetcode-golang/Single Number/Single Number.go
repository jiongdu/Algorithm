//选出数组中只出现一次的数字
func singleNonDuplicate(nums []int) int {
    var result int = 0
    for i := 0; i < len(nums); i++ {
        result ^= nums[i]
    }
    return result
}