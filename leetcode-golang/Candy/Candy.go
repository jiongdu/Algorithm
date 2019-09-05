//第一遍从左至右遍历：如果右边的等级高，则在左边的基础上加一个糖果
//第二遍从右至左遍历：如果左边的等级高，且左边的糖果数小于等于右边，则左边在右边的基础上加一个糖果
//加1的动作应该是在前一个的基础上，不应该在自己的基础上（在自己的基础上+1的话，会和相邻大于的相等）
func candy(ratings []int) int {
	sum := 0
	length := len(ratings)
	array := make([]int, length)
	for i := range array {
		array[i] = 1
	}
	for index := 1; index < length; index++ {
		if ratings[index-1] < ratings[index] {
			array[index] = array[index-1] + 1
		}
	}
	for index := length - 2; index >= 0; index-- {
		if ratings[index] > ratings[index+1] && array[index] <= array[index+1] {
			array[index] = array[index+1] + 1
		}
	}
	for i := range array {
		sum += array[i]
	}
	return sum
}

//一遍遍历的方法
func candy(ratings []int) int {
	sum := 0
	length := len(ratings)
	array := make([]int, length)
	cnt, pre := 0, 1
	for i := 1; i < length; i++ {
		//出现递增的时候
		if ratings[i] >= ratings[i-1] {
			//把之前递减的一波儿的计算了，然后重新赋值
			if cnt > 0 {
				res += cnt * (cnt + 1) / 2
				if cnt >= pre {
					res += cnt - pre + 1
					cnt = 0
					pre = 1
				}
			}
			if ratings[i] == ratings[i-1] {
				pre = 1
			} else {
				pre = pre + 1 //在递增，pre是之前同学得到的最大糖果数
			}
		} else {
			cnt += 1 //在连续递减的
		}
	}
	if cnt > 0 {
		res += cnt * (cnt + 1) / 2 //这一波儿连续递减的应该分配的糖果数，从1到cnt
		if cnt >= pre {
			res += cnt - pre + 1
		}
	}
	return res
}
