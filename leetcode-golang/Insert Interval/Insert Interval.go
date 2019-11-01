//plan A
import "sort"

func insert(intervals [][]int, newInterval []int) [][]int {

	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	// current := newInterval
	res := [][]int{}
	i := 0
	for i < len(intervals) {
		switch {
		//current[0] > intervals[i][1],继续寻找
		case newInterval[0] > intervals[i][1]:
			res = append(res, intervals[i])
		//current[0] <= intervals[i][1] && current[1] < intervals[i][0]
		case newInterval[1] < intervals[i][0]:
			res = append(res, newInterval)
			res = append(res, intervals[i:]...)
			return res
		//current[0] <= intervals[i][1] && current[1] >= intervals[i][0]
		case newInterval[1] >= intervals[i][0]:
			newInterval[0] = min(newInterval[0], intervals[i][0])
			newInterval[1] = max(newInterval[1], intervals[i][1])
		}
		i++
	}
	res = append(res, newInterval)
	return res
}

//plan B
func merge(intervals [][]int) [][]int {
	if len(intervals) == 0 {
		return [][]int{}
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	res := [][]int{}
	var current []int
	for i := 0; i < len(intervals); i++ {
		switch {
		case current == nil:
			current = intervals[i]
		case current[1] < intervals[i][0]:
			res = append(res, current)
			current = intervals[i]
		case current[1] < intervals[i][1]:
			current[1] = intervals[i][1]
		}
	}
	if len(current) > 0 {
		res = append(res, current)
	}
	return res
}

func insert(intervals [][]int, newInterval []int) [][]int {
	intervals = append(intervals, newInterval)
	if len(intervals) == 0 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool {
		return intervals[i][0] < intervals[j][0]
	})
	return merge(intervals)
}