import (
	"container/heap"
)

/*
 * 要实现这些方法的原因是
 * package heap
 * type Interface interface {
	 sort.Interface
	 Push(x interface{})
	 Pop() interface{}
	}
	而在sort.Interface中
	type Interface interface {
		Len() int
		Less(i, j int) bool
		Swap(i, j int)
	}
*/

type IntHeap []int

func (h IntHeap) Len() int {
	return len(h)
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

//大根堆
func (h IntHeap) Less(i, j int) bool {
	return h[i] > h[j]
}

func (h *IntHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func (h *IntHeap) Push(x interface{}) {
	*h = append(*h, x.(int))
}

func findKthLargest(nums []int, k int) int {
	var intHeap IntHeap = nums
	h := &intHeap
	heap.Init(h)
	for i := 0; i < k; i++ {
		if i == k-1 {
			return heap.Pop(h).(int)
		}
		heap.Pop(h)
	}
	return -1
}

// func findKthLargest(nums []int, k int) int {
// 	sort.Slice(nums, func(i, j int) bool {
// 		return nums[i] > nums[j]
// 	})
// 	return nums[k-1]
// }