int removeDuplicates(vector<int>& nums){
	if(nums.size()==0 || nums.size()==1) return nums.size();
	 int i=0;
	 for(int j=1;j<nums.size();j++){
		 if(nums[j]!=nums[i]){
			 nums[++i]=nums[j];
		 }
	 }
	 return i+1;
}


//可以允许出现两次重复
int removeDuplicates(vector<int>& nums){
	if(nums.size()<=2) return nums.size();
	int count=1;
	int i=0;
	for(int j=1;j<nums.size();j++){
		if(nums[i]==nums[j] && count<2){
			++count;
			nums[++i]=nums[j];
		}else if(nums[i]!=nums[j]){
			count=1;
			nums[++i]=nums[j];
		}
	}
	return i+1;
}