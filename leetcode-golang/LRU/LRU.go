type LRUCache struct {
	head  *node
	tail  *node
	store map[int]*node
	cap   int
}

type node struct {
	prev *node
	next *node
	key  int
	val  int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		store: make(map[int]*node),
		cap:   capacity,
	}
}

//移除该数据
func (this *LRUCache) removeFromChain(n *node) {
	if n == this.head {
		this.head = n.next
	}
	if n == this.tail {
		this.tail = n.prev
	}
	if n.prev != nil {
		n.prev.next = n.next
	}
	if n.next != nil {
		n.next.prev = n.prev
	}
}

//加在最前面
func (this *LRUCache) addToChain(n *node) {
	n.prev = nil
	h := this.head
	n.next = h
	if h != nil {
		h.prev = n
	}
	this.head = n
	if this.tail == nil {
		this.tail = n
	}
}

func (this *LRUCache) Get(key int) int {
	if node, ok := this.store[key]; ok {
		this.removeFromChain(node)
		this.addToChain(node)
		return node.val
	} else {
		return -1
	}
}

func (this *LRUCache) Put(key int, value int) {
	n, ok := this.store[key]
	if !ok {
		n = &node{
			key: key,
			val: value,
		}
		this.store[key] = n
	} else {
		n.val = value
		this.removeFromChain(n)
	}
	this.addToChain(n)
	if len(this.store) > this.cap {
		n = this.tail
		if n != nil {
			this.removeFromChain(n)
			delete(this.store, n.key)
		}
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */