import "sort"

func combinationSum2(candidates []int, target int) [][]int {
	res := [][]int{}
	temp := []int{}
	sort.Ints(candidates)
	combinationHelper2(candidates, target, 0, temp, &res)
	return res
}

func combinationHelper2(candidates []int, target, start int, temp []int, res *[][]int) {
	if target < 0 {
		return
	} else if target == 0 {
		*res = append(*res, append([]int{}, temp...))
		return
	} else {
		for i := start; i < len(candidates); i++ {
			// if i >= 1 && candidates[i] == candidates[i-1] && len(temp) == 0 { //这个只能去除开始点的重复
			// 	continue
			// }
			if i > start && candidates[i] == candidates[i-1] {
				continue
			}
			temp = append(temp, candidates[i])
			combinationHelper2(candidates, target-candidates[i], i+1, temp, res)
			temp = temp[:len(temp)-1]
		}
	}
}
