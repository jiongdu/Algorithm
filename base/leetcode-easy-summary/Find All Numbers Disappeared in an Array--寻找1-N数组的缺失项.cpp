/*
 *leetcode:448
 *寻找元素范围[1,n]中数组的缺失项，有的出现两次
 *n=nums.size()
 */
vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> ret;
	int len=nums.size();
	for(int i=0;i<len;i++){
		int index=abs(nums[i])-1;
		nums[index]=(nums[index]>0？-nums[index]:nums[index]);
	}
	for(int i=0;i<len;i++){
		if(nums[i]>0){
			ret.push_back(i+1);
		}
	}
	return ret;
}