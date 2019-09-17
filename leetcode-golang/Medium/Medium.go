import "container/heap"

type IntHeap []int

func (h IntHeap) Less(i, j int) bool {
	return h[i] < h[j]
}

func (h IntHeap) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h IntHeap) Len() int {
	return len(h)
}

func (h *IntHeap) Push(v interface{}) {
	*h = append(*h, v.(int))
	return
}

func (h *IntHeap) Pop() (v interface{}) {
	old := *h
	val := old[len(old)-1]
	*h = old[:len(old)-1]
	return val
}

//再次用到了堆，对前len(nums)/2构建一个最小堆（长度保证），然后从len(nums)/2开始，与最小值比较，大于则变换堆
func median(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	var intHeap IntHeap = nums[0 : len(nums)/2+1]
	h := &intHeap
	heap.Init(h)
	for i := len(nums)/2 + 1; i < len(nums); i++ {
		minHeapValue := heap.Pop(h).(int)
		if nums[i] > minHeapValue {
			heap.Push(h, nums[i])
		} else {
			heap.Push(h, minHeapValue)
		}
	}
	return heap.Pop(h).(int)
}