func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	length := len(nums1) + len(nums2)
	if length%2 == 1 {
		return findKthSmallestNum(nums1, nums2, 0, 0, length/2+1)
	} else {
		return (findKthSmallestNum(nums1, nums2, 0, 0, length/2) + findKthSmallestNum(nums1, nums2, 0, 0, length/2+1)) / 2
	}
	return 0
}

func findKthSmallestNum(nums1 []int, nums2 []int, start1, start2, k int) float64 {
	len1, len2 := len(nums1), len(nums2)
	if start1 >= len1 {
		//如果数组nums1为空，则数组nums2第k个元素就是两个数组中第k小的元素
		return float64(nums2[start2+k-1])
	}
	if start2 >= len2 {
		return float64(nums1[start1+k-1])
	}
	if k == 1 {
		//如果k为1，则两个数组第一个元素较小的那个就是两个数组第k小的元素
		return min(float64(nums1[start1]), float64(nums2[start2]))
	}
	//两个数组第k/2项元素的下标
	index1 := start1 + k/2 - 1
	index2 := start2 + k/2 - 1
	num1, num2 := 0, 0
	if index1 < len1 {
		//如果数组nums1有k/2项，则将该元素赋值给num1
		num1 = nums1[index1]
	} else {
		//如果数组nums1已经不足k/2项，则删除nums2前k/2项，即将start2增加k/2
		return findKthSmallestNum(nums1, nums2, start1, start2+k/2, k-k/2)
	}
	if index2 < len2 {
		num2 = nums2[index2]
	} else {
		return findKthSmallestNum(nums1, nums2, start1+k/2, start2, k-k/2)
	}
	if num1 < num2 {
		//如果数组nums1中第k/2项元素较小，删除数组nums1前k/2项元素
		return findKthSmallestNum(nums1, nums2, start1+k/2, start2, k-k/2)
	} else {
		return findKthSmallestNum(nums1, nums2, start1, start2+k/2, k-k/2)
	}
}

func min(a, b float64) float64 {
	if a < b {
		return a
	}
	return b
}