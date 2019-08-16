import "math/rand"

type Solution struct {
	Sum []int
}

func Constructor(w []int) Solution {
	sum := w
	for i := 1; i < len(w); i++ {
		sum[i] = sum[i-1] + w[i]
	}
	return Solution{Sum: sum}
}

func (this *Solution) PickIndex() int {
	x := rand.Intn(this.Sum[len(this.Sum)-1])
	left, right := 0, len(this.Sum)-1
	for left < right {
		mid := left + (right-left)/2
		if this.Sum[mid] <= x {
			left = mid + 1
		} else {
			right = mid
		}
	}
	return right
}