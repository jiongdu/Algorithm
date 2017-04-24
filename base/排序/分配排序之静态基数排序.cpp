/*
 分析：
 桶排序只适合m很小的情况
 基数排序：当m很大时，可以将一个记录的值拆分成多个部分来进行比较
 空间代价：
 O(n+r)：临时数组(n)和r个计数器
 时间复杂度: O(d*(n+r))  即d次桶式排序
 稳定性：稳定
*/

void RadixSort(vector<int>& nums, int d, int r){
	int n=nums.size();
	vector<int> temp(n,0);
	vector<int> count(r,0);		//r:radix,10
	int radix=1;
	int i,j,k;
	for(i=1;i<=d;i++){		//d:排序码的个数
		for(j=0;j<r;j++){
			count[j]=0;
		}
		for(j=0;j<n;j++){
			k=(nums[j]/radix)%r;
			count[k]++;
		}
		for(j=1;j<r;j++){
			count[j]=count[j]+count[j-1];
		}
		for(j=n-1;j>=0;j--){
			k=(nums[j]/radix)%r;
			count[k]--;
			temp[count[k]]=nums[j];
		}
		for(j=0;j<n;j++){
			nums[j]=temp[j];
		}
		radix*=r;
	}
}

