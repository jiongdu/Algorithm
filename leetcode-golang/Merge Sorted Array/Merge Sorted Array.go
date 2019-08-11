//特别注意i>=0的判定，这是考虑到如果nums1输入为空, nums2包含值的情况，因为最终使用的是nums1返回
func merge(nums1 []int, m int, nums2 []int, n int)  {
    target := m + n -1
    i, j := m-1, n-1
    for j >= 0 {
        if i >= 0 && nums1[i] >= nums2[j] {
            nums1[target] = nums1[i]
            target--
            i--
        } else {
            nums1[target] = nums2[j]
            target--
            j--
        }
    }
}