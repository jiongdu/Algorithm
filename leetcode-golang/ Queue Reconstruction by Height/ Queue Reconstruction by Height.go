import "sort"

func reconstructQueue(people [][]int) [][]int {
	res := [][]int{}
	//按照<height大，k小>的顺序排序
	sort.Slice(people, func(i, j int) bool {
		return people[i][0] > people[j][0] || (people[i][0] == people[j][0] && people[i][1] < people[j][1])
	})

	for _, v := range people {
		insert(&res, v[1], v)
	}
	return res
}

func insert(s *[][]int, p int, v []int) {
	*s = append(*s, []int{})
	copy((*s)[p+1:], (*s)[p:])
	(*s)[p] = v
}
