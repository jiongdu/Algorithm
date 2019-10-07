type MinStack struct {
	minElement []int
	data       []int
}

/** initialize your data structure here. */
func Constructor() MinStack {
	return MinStack{
		minElement: make([]int, 0),
		data:       make([]int, 0),
	}
}

func (this *MinStack) Push(x int) {
	this.data = append(this.data, x)
	if len(this.minElement) == 0 {
		this.minElement = append(this.minElement, x)
	} else {
		length := len(this.minElement)
		if this.minElement[length-1] > x {
			this.minElement = append(this.minElement, x)
		} else {
			this.minElement = append(this.minElement, this.minElement[length-1])
		}
	}
}

func (this *MinStack) Pop() {
	length := len(this.data)
	if length == 0 {
		return
	}
	this.data = this.data[:length-1]
	this.minElement = this.minElement[:length-1]
}

func (this *MinStack) Top() int {
	return this.data[len(this.data)-1]
}

func (this *MinStack) GetMin() int {
	return this.minElement[len(this.minElement)-1]
}

/**
 * Your MinStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.GetMin();
 */