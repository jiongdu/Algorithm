//汇聚了所有常用dfs的情况，重点突破

//22:Generate Parentheses
//这里麻烦的地方在于：不能理解以什么规则去产生(、)符号
//重点要理解用left,right来代表剩余两个符号的个数
func generateParenthesis(n int) []string {
	left, right := n, n //剩余两个符号的个数
	res := []string{}
	cur := []byte{}
	generateParenthesisHelp(left, right, cur, &res)
	return res
}
func generateParenthesisHelp(left, right int, cur []byte, res *[]string) {
	if left > right {
		return
	}
	if left == 0 && right == 0 { //二者剩余都为0
		*res = append(*res, string(cur))
	} else {
		if left > 0 {
			generateParenthesisHelp(left-1, right, append(cur, '('), res)
		}
		if right > 0 {
			generateParenthesisHelp(left, right-1, append(cur, ')'), res)
		}
	}
	return
}

class Solution {
	public:
		vector<string> generateParenthesis(int n) {
			int left = n, right = n;
			vector<string> res;
			// string cur;
			helper(left, right, "", res);
			return res;
		}
		void helper(int left, int right, string cur, vector<string>& res) {
			if (left > right) {
				return;
			}
			if (left == 0 && right == 0) {
				res.push_back(cur);
				return;
			} else {
				if (left > 0) {
					helper(left-1, right, cur+"(", res);
				}
				if (right > 0) {
					helper(left, right-1, cur+")", res);
				}
			}
			return;
		}
};

//31:Next Permutation
//下一个排列，记住方法
func nextPermutation(nums []int)  {
	//第一步，从右向左找到第一个下降的
	right := -1
	for i := len(nums)-2; i >= 0; i-- {
		if nums[i] < nums[i+1] {
			right = i
			break
		}
	}
	if right == -1 {		//没有，反转返回
		reverse(nums)
		return
	}
	j := len(nums)-1
	for ; j>=0; j-- {
		if nums[j] > nums[right] {
			break
		}
	}
	//交换
	nums[right], nums[j] = nums[j], nums[right]
	reverse(nums[right+1:])
}

func reverse(nums []int) {
	for i := 0; i < len(nums)/2;i++ {
		nums[i], nums[len(nums)-1-i] = nums[len(nums)-1-i], nums[i]
	}
}

//39:Combination Sum
//怎么做到后面不会再选取前面的
//不错，能自己改出来了
func combinationSum(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	temp := make([]int, 0)
	res := make([][]int, 0)
	combinationSumHelp(candidates, temp, target, &res, 0)
	return res
}

func combinationSumHelp(candidates []int, temp []int, target int, res *[][]int, start int) {
	if target < 0 {
		return 
	}
	if target == 0 {
		*res = append(*res, append([]int{}, temp...))
		return
	}
	//从start开始，为了做到后面不会再选取前面的，递归参数为i
	for i := start; i < len(candidates); i++ {
		temp = append(temp, candidates[i])
		combinationSumHelp(candidates, temp, target-candidates[i], res, i)
		temp = temp[:len(temp)-1]
	}
}


//40:Combination Sum ii
//每个位置上不能重复
//很强啊，自己改出来了
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	temp := make([]int, 0)
	res := make([][]int, 0)
	combinationSumHelp2(candidates, temp, target, &res, 0)
	return res
}

func combinationSumHelp2(candidates []int, temp []int, target int, res *[][]int, start int) {
	if target < 0 {
		return 
	}
	if target == 0 {
		*res = append(*res, append([]int{}, temp...))
		return
	}
	for i := start; i < len(candidates); i++ {
		if i > start && candidates[i] == candidates[i-1] {
			continue
		}
		temp = append(temp, candidates[i])
		combinationSumHelp2(candidates, temp, target-candidates[i], res, i+1)
		temp = temp[:len(temp)-1]
	}
}

//46:Permutations
//全排列
//继续ok
func permute(nums []int) [][]int {
	res := [][]int{}
	permuteHelp(nums, 0, &res)
}

func permuteHelp(nums []int, start, res *[][]int) {
	if start > len(nums) {
		return
	}
	if start == len(nums) {
		*res = append(*res, nums)
		return 
	}

	for i := start; i < len(nums); i++ {
		nums[i], nums[start] = nums[start], nums[i]
		permuteHelp(nums, start+1, res)
		nums[i], nums[start] = nums[start], nums[i]
	}
}

//47:Permutations II
//全排列，可能会有重复
//难以理解
func permuteUnique(nums []int) [][]int {
	sort.Ints(nums)
	res := [][]int{}
	permuteUniqueHelp(nums, 0, &res)
	return res
}

func permuteUniqueHelp(nums []int, start int, res *[][]int) {
	// if start > len(nums) {
	// 	return
	// }
	if start >= len(nums) {
		*res = append(*res, append([]int{}, nums...))
		return
	}
	freq := make(map[int]bool)
	for i := start; i < len(nums); i++ {
		if _, ok := freq[nums[i]]; ok {		
			continue
		}
		nums[i], nums[start] = nums[start], nums[i]
		permuteUniqueHelp(nums, start+1, res)
		nums[i], nums[start] = nums[start], nums[i]
		freq[nums[i]] = true
	}
}
