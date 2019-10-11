func maxPoints(points [][]int) int {
	if len(points) == 0 || len(points[0]) == 0 {
		return 0
	}
	res := 0
	for i := 0; i < len(points); i++ {
		duplicate := 1
		for j := i + 1; j < len(points); j++ {
			cnt := 0
			x1, y1 := points[i][0], points[i][1]
			x2, y2 := points[j][0], points[j][1]
			if x1 == x2 && y1 == y2 {
				duplicate++
				continue
			}
			for k := 0; k < len(points); k++ {
				x3, y3 := points[k][0], points[k][1]
				//行列式
				if x1*y2+x2*y3+x3*y1-x3*y2-x2*y1-x1*y3 == 0 {
					cnt++
				}
			}
			if res < cnt {
				res = cnt
			}
		}
		if res < duplicate {
			res = duplicate
		}
	}
	return res
}