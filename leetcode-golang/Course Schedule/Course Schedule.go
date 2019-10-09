func canFinish(numCourses int, prerequisites [][]int) bool {
	if numCourses <= 0 {
		return false
	}
	if len(prerequisites) == 0 {
		return true
	}
	inDegrees := make([]int, numCourses, numCourses)
	adjList := make([][]int, numCourses) //邻接？
	queue := make([]int, 0, numCourses)
	removed := 0

	for _, edge := range prerequisites {
		to, from := edge[0], edge[1]
		if from == to {
			return false
		}
		inDegrees[to]++                           //to节点的入度
		adjList[from] = append(adjList[from], to) //邻接矩阵的味道，将from的所有to存一个array
	}
	for i, n := range inDegrees {
		//入度为0
		if n == 0 {
			queue = append(queue, i) //queue中保存的是入度为0的点
			removed++
		}
	}
	for len(queue) > 0 {
		n := queue[0] //n的入度为0，看看它的出度
		for _, out := range adjList[n] {
			inDegrees[out]-- //减去该出度对应点的入度
			if inDegrees[out] == 0 {
				queue = append(queue, out)
				removed++
			}
		}
		if len(queue) <= 1 { //最后一个也已经remove了，因此小于等于1即可break
			break
		}
		queue = queue[1:]
	}
	return removed == numCourses
}