import "sort"

func getSortStrs(str string) string {
	sortByte := []byte(str)
	sort.Slice(sortByte, func(i, j int) bool {
		return sortByte[i] < sortByte[j]
	})
	return string(sortByte)
}

func groupAnagrams(strs []string) [][]string {
	m := make(map[string][]string)
	res := [][]string{}
	for i := 0; i < len(strs); i++ {
		m[getSortStrs(strs[i])] = append(m[getSortStrs(strs[i])], strs[i])
	}
	for strKey, _ := range m {
		// tempSlice := m[strKey]
		res = append(res, m[strKey])
	}
	return res
}