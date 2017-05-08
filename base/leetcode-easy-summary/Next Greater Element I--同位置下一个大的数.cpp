/*
 *leetcode: 496
 *给定两个数组，第一个是第二个的子集，找出第一个数组中每个数
 *在第二个数组相同下标位置之后第一个比它大的数，没有返回-1
 */
 
vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums){
	int len1 = findNums.size();
	int len2 = nums.size();
	vector<int> ret;
	if(len1==0 || len2==0) return ret;
	ret.reserve(len1);
	stack<int> s;
	map<int, int> imap;
	int i=0;
	for(int i=0;i<len2;i++){
		while(!s.empty()&&s.top()<nums[i]){
			imap[s.top()]=nums[i];
			s.pop();
		}
		s.push(nums[i]);
	}
	for(int i=0;i<len1;i++){
		if(imap.find(findNums[i])!=findNums.end()){
			ret.push_back(imap[findNums[i]]);
		}else{
			ret.push_back(-1);
		}
	}
	return ret;
}