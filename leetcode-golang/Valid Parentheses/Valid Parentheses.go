package leetcode_valid_parentheses

func isValid(s string) bool {
	str := new(stack)

	for _, b := range s {
		switch b {
		case '(', '[', '{':
			str.push(b)
		case ')', ']', '}':
			//要和拿出来的最近的那个匹配，可以这样用 r != matching[b],不用担心不在，就是不相等
			if r, ok := str.pop(); !ok || r != matching[b] {
				return false
			}
		}
	}

	if len(*str) > 0 {
		return false
	}
	return true
}

var matching = map[rune]rune{
	')': '(',
	']': '[',
	'}': '{',
}

type stack []rune

func (s *stack) push(b rune) {
	*s = append(*s, b)
}

func (s *stack) pop() (rune, bool) {
	if len(*s) > 0 {
		res := (*s)[len(*s)-1]
		*s = (*s)[:len(*s)-1]
		return res, true
	}
	return 0, false
}
