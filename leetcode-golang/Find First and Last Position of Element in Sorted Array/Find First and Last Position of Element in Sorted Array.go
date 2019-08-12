//从下面两个可以看出，right取len(nums),还是len(nums)-1都ok，在循环判定条件中加以区分即可
//不然两边的两个元素可能会取不到
func searchRange(nums []int, target int) []int {
    length := len(nums)
    left, right := 0, length
    for left < right {
        mid := left + (right-left)/2
        if nums[mid] < target {
            left = left+1
        } else if nums[mid] > target {
            right = right-1
        } else if nums[mid] == target {
            ret1, ret2 := mid, mid
            for ret1 >= 0 && nums[ret1] == target {
                ret1--
            }
            for ret2 < length && nums[ret2] == target {
                ret2++
            }
            return []int{ret1+1, ret2-1}
        }
    }
    return []int{-1, -1}
}

///
func searchRange(nums []int, target int) []int {
    length := len(nums)-1
    left, right := 0, length
    for left <= right {
        mid := left + (right-left)/2
        if nums[mid] < target {
            left = left+1
        } else if nums[mid] > target {
            right = right-1
        } else if nums[mid] == target {
            ret1, ret2 := mid, mid
            for ret1 >= 0 && nums[ret1] == target {
                ret1--
            }
            for ret2 <= length && nums[ret2] == target {
                ret2++
            }
            return []int{ret1+1, ret2-1}
        }
    }
    return []int{-1, -1}
}