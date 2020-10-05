import "strings"

func wordPattern(pattern string, s string) bool {
	ss := strings.Fields(s)
	if len(pattern) != len(ss) {
		return false
	}
	p1 := make(map[byte]int)
	s1 := make(map[string]int)
	i := 0
	n := len(pattern)
	for ; i < n; i++ {
		if p1[pattern[i]] != s1[ss[i]] {
			return false
		}
		p1[pattern[i]], s1[ss[i]] = i+1, i+1
	}
	return i == n
}	