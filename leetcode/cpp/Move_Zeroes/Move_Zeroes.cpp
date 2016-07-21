class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left=0,right=0;
        while(right < n)
        {
            if(nums[right]){
                nums[left] = nums[right];
                left++;
            }
            right++;
        }
        while(left<n)
        {
            nums[left++]=0;
        }
    }
};
