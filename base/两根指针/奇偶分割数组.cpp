void partitionArray(vector<int>& nums){
	if(nums.size()==0) return;
	int left=0,right=nums.size()-1;
	while(left<right){
		while(nums[left]%2==1){
			left++;
		}
		while(nums[right]%2==0){
			right--;
		}
		if(left<right){
			std::swap(nums[left], nums[right]);
			left++;
			right--;
		}
	}
}