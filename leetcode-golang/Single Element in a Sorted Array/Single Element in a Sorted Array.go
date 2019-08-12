//选出数组中只出现一次的数字（其余两次，且数组有序）
//很巧妙的一种方法，mid和mid^1互为伙伴，不论是奇数还是偶数正好
func singleNonDuplicate(nums []int) int {
    left, right := 0, len(nums) - 1
    for left < right {
        mid := left + (right-left) / 2
        if nums[mid] == nums[mid^1] {
            left = mid + 1
        } else {
            right = mid
        }
    }
    return nums[left]
}