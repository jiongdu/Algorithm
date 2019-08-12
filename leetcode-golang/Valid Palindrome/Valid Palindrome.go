func isPalindrome(s string) bool {
    ss := strings.ToLower(s)
    left, right := 0, len(ss)-1
    for left <= right {
        for !((ss[left] >= '0' && ss[left] <= '9') || (ss[left] >= 'a' && ss[left] <='z')) && left < right {
            left++
        }
        for !((ss[right] >= '0' && ss[right] <= '9') || (ss[right] >= 'a' && ss[right] <='z')) && left < right {
            right--
        }
        if ss[left] != ss[right] {
            return false
        }
        left++
        right--
    }
    return true
}

//golang中判断是否为数字/字母的方法
func isPalindrome(s string) bool {
    i, j := 0, len(s) - 1
    for i < j {
        if !isAlphaNumeric(s[i]) { i++; continue }
        if !isAlphaNumeric(s[j]) { j--; continue }
        if unicode.ToLower(rune(s[i])) != unicode.ToLower(rune(s[j])) { return false }
        i, j = i + 1, j - 1
    }
    return true
}

func isAlphaNumeric(b byte) bool {
    return unicode.IsLetter(rune(b)) || unicode.IsNumber(rune(b))
}