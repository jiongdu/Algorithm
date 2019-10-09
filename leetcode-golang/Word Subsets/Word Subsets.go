//golang基本用法用得好
func wordSubsets(A []string, B []string) []string {
	type hashT [26]int
	//匿名函数
	hash := func(a string) (h hashT) {
		for _, c := range a {
			h[int(c-'a')]++
		}
		return
	}

	//取多的，key
	hashMerge := func(a hashT, b hashT) hashT {
		for i := 0; i < 26; i++ {
			if b[i] > a[i] {
				a[i] = b[i]
			}
		}
		return a
	}

	hashHas := func(a hashT, b hashT) bool {
		for i := 0; i < 26; i++ {
			if b[i] > a[i] {
				return false
			}
		}
		return true
	}

	a := make([]hashT, len(A))
	var b hashT

	for i, A_ := range A {
		a[i] = hash(A_)
	}
	for _, B_ := range B {
		b = hashMerge(b, hash(B_))
	}

	result := make([]string, 0, len(A))
	for i := range A {
		if hashHas(a[i], b) {
			result = append(result, A[i])
		}
	}
	return result
}
