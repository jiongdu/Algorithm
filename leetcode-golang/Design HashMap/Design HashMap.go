type MyHashMap struct {
	capacity int
	data     []int
}

func Constructor() MyHashMap {
	capacity := 1000001
	data := make([]int, capacity)
	for i := range data {
		data[i] = -1
	}
	return MyHashMap{
		capacity: capacity,
		data:     data,
	}
}

func (hm *MyHashMap) Hash(key int) int {
	return key % hm.capacity
}

func (hm *MyHashMap) Put(key int, value int) int {
	hm.data[hm.Hash(key)] = value
}

func (hm *MyHashMap) Get(key int) int {
	return hm.data[hm.Hash(key)]
}

func (hm *MyHashMap) Remove(key int) {
	hm.data[hm.Hash(key)] = -1
}