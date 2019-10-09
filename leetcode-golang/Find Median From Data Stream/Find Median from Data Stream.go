import "container/heap"

type MedianFinder struct {
	Smaller ByDESC //递减，大根堆
	Larger  ByASC  //递增，小根堆
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	s, l := []int{}, []int{}
	return MedianFinder{ByDESC(s), ByASC(l)}
}

func (this *MedianFinder) AddNum(num int) {
	if len(this.Smaller) == 0 {
		heap.Push(&this.Smaller, num)
		return
	}
	if this.Smaller[0] >= num {
		heap.Push(&this.Smaller, num)
		if len(this.Smaller)-len(this.Larger) > 1 {
			maxInSmaller := heap.Pop(&this.Smaller)
			i, _ := maxInSmaller.(int)
			heap.Push(&this.Larger, i)
		}
	} else {
		heap.Push(&this.Larger, num)
		if len(this.Larger)-len(this.Smaller) > 0 {
			minInLarger := heap.Pop(&this.Larger)
			i, _ := minInLarger.(int)
			heap.Push(&this.Smaller, i)
		}
	}
}

func (this *MedianFinder) FindMedian() float64 {
	//使用两个堆，如果二者之和是偶数，相加/2，如果是奇数，返回smaller的堆顶元素
	slen, llen := len(this.Smaller), len(this.Larger)
	if (slen+llen)%2 == 0 {
		return float64(this.Smaller[0]+this.Larger[0]) / 2.0
	} else {
		return float64(this.Smaller[0])
	}
}

type ByASC []int

func (b ByASC) Len() int {
	return len(b)
}

func (b ByASC) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

func (b ByASC) Less(i, j int) bool {
	return b[i] < b[j]
}

func (b *ByASC) Pop() interface{} {
	bv := *b
	val := bv[len(bv)-1]
	*b = bv[:len(bv)-1]
	return val
}

func (b *ByASC) Push(inte interface{}) {
	i, _ := inte.(int)
	*b = append(*b, i)
}

type ByDESC []int

func (b ByDESC) Len() int {
	return len(b)
}

func (b ByDESC) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

func (b ByDESC) Less(i, j int) bool {
	return b[i] > b[j]
}

func (b *ByDESC) Pop() interface{} {
	bv := *b
	val := bv[len(bv)-1]
	*b = bv[:len(bv)-1]
	return val
}

func (b *ByDESC) Push(inte interface{}) {
	i, _ := inte.(int)
	*b = append(*b, i)
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */