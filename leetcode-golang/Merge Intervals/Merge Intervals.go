import "sort"

func merge(intervals [][]int) [][]int {
	merged := make([][]int, 0, len(intervals))
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	var current []int
	//正确的思路是：
	//首先判断current是否为空，如果为空，则把intervals[i]赋值给current，主要是解决第一个intervals的问题
	//然后判定current[1](最大值)是否比intervals[i][0](最小值)小，这样就没有交集，可以放入结果数组
	//然后判定current[1]（最大值）是否比intervals[i][1](最大值)小，因为上一个条件的判定和本条件互斥，
	//即进行到这里应该存在cucrent[1] > intervals[i][0]，所以如果current[1] < intervals[i][1]，这样就需要
	//合并，将current[1]更改为intervals[i][1]

	//如果第二个case的判定和第三个之间顺序错误，会导致不满足intervals[i][0] < current[1]的情况也会被误判定为
	//intervals[i][1] > current[1]，导致没有集合交集的也进行了合并
	//原代码中没有使用break的原因是各case条件之间不存在冲突，所以不会出现顺序执行的情况，各case结束时加break效果一样

	//这样可能会好理解些
	for i := range intervals {
		switch {
		case current == nil:
			current = intervals[i]
			break
		case current[1] < intervals[i][0]:
			merged = append(merged, current)
			current = intervals[i]
			break
		case current[1] < intervals[i][1]: //暗含current[1] > intervals[i][0]
			current[1] = intervals[i][1]
			break
		}
	}
	// for i := range intervals {
	// 	switch {
	// 	case current == nil:
	// 		current = intervals[i]
	// 	case intervals[i][0] > current[1]:
	// 		merged = append(merged, current)
	// 		current = intervals[i]
	// 	case intervals[i][1] > current[1]:
	// 		current[1] = intervals[i][1]
	// 	}
	// }
	if current != nil {
		merged = append(merged, current)
	}
	return merged
}