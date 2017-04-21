/*
 分析:
 数组长度为n，所有记录区间[0,m)上
 时间复杂度O(n+m)
 空间代价：m个计数器，长度为n的临时数组
 适用于m相对于n很小的情况
 稳定性：稳定
 */
 
 void BucketSort(vector<int>& nums, int max){
	 int n=nums.size();
	 vector<int> temp(begin(nums), end(nums));
	 vector<int> count(max);
	 for(int i=0;i<max;i++){
		 count[i]=0;
	 }
	 for(int i=0;i<n;i++){
		 count[nums[i]]++;
	 }
	 for(int i=0;i<max;i++){
		 count[i]=count[i-1]+count[i];
	 }
	 for(int i=n-1;i>=0;i--){		//尾部开始，保证稳定性
		 nums[--count[temp[i]]]=temp[i];
	 }
}