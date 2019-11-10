import (
	"math"
	"sort"
)

func subsets(nums []int) [][]int {
	length := len(nums)
	combinationLength := int(math.Pow(2, float64(length)))
	result := make([][]int, combinationLength)
	for i := 0; i < combinationLength; i++ {
		result[i] = make([]int, 0)
	}
	for i := 0; i < length; i++ {
		for j := 0; j < combinationLength; j++ {
			if j>>uint32(i)&1 > 0 { //移位操作必须是uint32类型
				result[j] = append(result[j], nums[i])
			}
		}
	}
	return result
}

func subsets(nums []int) [][]int {
	sort.Ints(nums)
	temp := make([]int, 0)
	res := make([][]int, 0)
	combineHelper(nums, 0, temp, &res)
	return res
}

func combineHelper(nums []int, pos int, temp []int, res *[][]int) {
	*res = append(*res, append([]int{}, temp...))
	for i := pos; i < len(nums); i++ {
		temp = append(temp, nums[i])
		combineHelper(nums, i+1, temp, res)
		temp = temp[:len(temp)-1]
	}
}
