import "sort"

func combinationSum(candidates []int, target int) [][]int {
	res := [][]int{}
	temp := []int{}
	sort.Ints(candidates)
	combinationHelper(candidates, target, 0, temp, &res)
	return res
}

func combinationHelper(candidates []int, target, start int, temp []int, res *[][]int) {
	if target < 0 {
		return
	} else if target == 0 {
		*res = append(*res, append([]int{}, temp...))
		// c := make([]int, len(temp))
		// copy(c, temp)
		// *res = append(*res, c)
	} else {
		for i := start; i < len(candidates); i++ {
			temp = append(temp, candidates[i])
			combinationHelper(candidates, target-candidates[i], i, temp, res)
			temp = temp[:len(temp)-1]
		}
	}
}

//c++
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
	vector<vector<int> > res;
	vector<int> temp;
	std::sort(candidates.begin(), candidates.end());
	combinationSumDFS(candidates, target, 0, temp, res);            //都是这样递归的思想
	return res;
}
void combinationSumDFS(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int> >& res){
	if(target < 0) return;
	else if(target == 0) res.push_back(temp);
	else{
		for(int i=start;i<candidates.size();i++){
			temp.push_back(candidates[i]);
			combinationSumDFS(candidates, target-candidates[i], i, temp, res);
			temp.pop_back();
		}
	}
}