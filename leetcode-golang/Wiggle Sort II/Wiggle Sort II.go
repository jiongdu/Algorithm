import "sort"

//重排数组，使得大小大小这样间隔
func wiggleSort(nums []int) {
	if len(nums) == 0 {
		return
	}
    temp := make([]int, len(nums))
    copy(temp, nums)
	sort.Ints(temp)
    mid, right := (len(temp)-1)/2, len(nums)-1
	i := 0
    for mid >= 0 || right > (len(temp)-1)/2 {
		if i & 1 == 1 {
			nums[i] = temp[right]
			right--
		} else {
			nums[i] = temp[mid]
			mid--
		}
        i++
	}
}