//每个Trie结构保存子节点
//叶子节点保存value
type Trie struct {
    children []*Trie
	value    string
}


/** Initialize your data structure here. */
//显示中可能有各种字符，而不是一个固定的大小范围
func Constructor() Trie {
    return Trie{
        children: make([]*Trie, 26, 26),
        value: "",
    }
}

func (this *Trie) getChild(i int) *Trie {
	return this.children[i]
}

func (this *Trie) setChild(i int, child *Trie) {
	this.children[i] = child
}

func (this *Trie) setValue(s string) {
	this.value = s
}

func (this *Trie) getValue() string {
	return this.value
}

/** Inserts a word into the trie. */
func (this *Trie) Insert(word string)  {
    cur := this
    for _, v := range word {
        if cur.getChild(int(v-'a')) == nil {
            temp := Constructor()
            cur.setChild(int(v-'a'), &temp)
        }
        cur = cur.getChild(int(v - 'a'))
    }
    cur.setValue(word)
}


/** Returns if the word is in the trie. */
func (this *Trie) Search(word string) bool {
    cur := this
    for _, v := range word {
        if cur.getChild(int(v-'a')) == nil {
            return false
        }
        cur = cur.getChild(int(v-'a'))
    }
    return cur.getValue() == word
}


/** Returns if there is any word in the trie that starts with the given prefix. */
func (this *Trie) StartsWith(prefix string) bool {
    cur := this
    for _, v := range prefix {
        if cur.getChild(int(v-'a')) == nil {
            return false
        }
        cur = cur.getChild(int(v-'a'))
    }
    return true
}


/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */