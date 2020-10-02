import "container/list"

type RecentCounter struct {
	l *list.List
}

func Constructor() RecentCounter {
	return RecentCounter{
		l: list.New(),
	}
}

func (this *RecentCounter) Ping(t int) int {
	this.l.PushBack(t)
	for this.l.Front().Value.(int) < t-3000 {
		this.l.Remove(this.l.Front())
	}
	return this.l.Len()
}

/**
 * Your RecentCounter object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Ping(t);
 */